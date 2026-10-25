#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include<algorithm>
int main() {
    double v0 = 50.0;
    double g = 9.8;
    double dt = 1.0;

    if (v0 <= 0) {
        std::cout <<  "Начальная скорость v0 должна быть больше 0" << std::endl;
        return 1;
    }

    std::vector<double> times;
    std::vector<double> heights;
    times.reserve((int)(v0 * 2 / g / dt));
    heights.reserve((int)(v0 * 2 / g / dt));

    for (double t = 0.0; t <= 1000.0; t += dt) {
        double h = v0 * t - 0.5 * g * t * t;
        if (h < 0) break;
        times.push_back(t);
        heights.push_back(h);
    }

    // Заголовок таблицы
    std::cout << std::setw(10) << "t (с)"
              << std::setw(15) << "h (м)"
              << std::endl;
    std::cout << std::string(25, '-') << std::endl;
    for (size_t i = 0; i < times.size(); i++) {
        std::cout << std::setw(10) << std::fixed << std::setprecision(2) << times[i]
                  << std::setw(15) << std::fixed << std::setprecision(2) << heights[i]
                  << std::endl;
    }


	if (heights.empty()) {
		std::cout<<"Данных нет"<<std::endl;
		return 1;
	}
	size_t idx_max = 0;
	for (size_t i = 1; i < heights.size(); ++i){

		if (heights[i] > heights[idx_max]) {
			idx_max = i;
		}
	}
	std::cout << "Максимальная высота : " << std::fixed  << std::setprecision(2) << heights[idx_max]
			  <<"Достигнута на времени t = " << times[idx_max]<<std::endl;

	return 0;

}



