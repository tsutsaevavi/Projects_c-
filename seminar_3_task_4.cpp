#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include<algorithm>
#include <numeric>

int main() {
    double v0 = 50.0;
    double g = 9.8;
    double dt = 1.0;
    double t_max = 1000;
    std::vector<double> times, velocities;

    for (double t = 0.0; t <= t_max; t += dt){
    	 double h = v0 * t - 0.5 * g * t * t;
    	 if ( h < 0){
    		 break;
    	 }
    	 double v = v0 - g * t;
    	 if (v < -100.0) {
    	            std::cout << "Скорость слишком отрицательная!" << std::endl;
    	            break;
    	        }
    	 times.push_back(t);
    	 velocities.push_back(v);

    }

    if (velocities.empty()) {
    	std::cout<<"Пусто!"<<std::endl;
    	return 1;
    }
    std::cout << std::setw(10) << "t (с)"
                  << std::setw(15) << "v (м/с)"
                  << std::endl;
        std::cout << std::string(25, '-') << std::endl;


        for (size_t i = 0; i < times.size(); i++) {
            std::cout << std::setw(10) << std::fixed << std::setprecision(2) << times[i]
                      << std::setw(15) << std::fixed << std::setprecision(2) << velocities[i]
                      << std::endl;
        }


        std::cout << std::string(25, '-') << std::endl;
        std::cout << "Точный момент смены знака скорости : t = "
                  << std::fixed << std::setprecision(2) << (v0 / g) << " с." << std::endl;


        double sum = std::accumulate(velocities.begin(), velocities.end(),
        0.0);


        double avg = sum / velocities.size();
        std::cout<<"Среднее "<< std::fixed << std::setprecision(2) << avg << "м/c" << std::endl;

        //вычисление интеграла методом трапеций
        double integral = 0.0;
        for (size_t i = 0; i <velocities.size()-1 ; ++i){
        	integral += 0.5 * (velocities[i] + velocities[i+1]) * dt;
        }
        double T = times.back()-times.front();//время в начале и конце пути
        if (T > 0){
        double avg_integral = integral / T;
        std::cout << "Интегральное (более физическое) среднее: "
                          << std::fixed << std::setprecision(2) << avg_integral << " м/с" << std::endl;
        }
		return 0;
}
