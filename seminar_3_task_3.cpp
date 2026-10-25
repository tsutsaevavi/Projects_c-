#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include<algorithm>
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

        return 0;
    }


