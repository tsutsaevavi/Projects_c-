#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <iterator>

int main() {
    double v0 = 50.0;
    double g = 9.8;
    double dt = 0.1;
    double t_max = 1000.0;

    std::vector<double> times;
    std::vector<double> heights;

    times.reserve(static_cast<int>(v0 * 2 / g / dt) + 1);
    heights.reserve(static_cast<int>(v0 * 2 / g / dt) + 1);

    for (double t = 0.0; t <= t_max; t += dt) {
        double h = v0 * t - 0.5 * g * t * t;

        if (h < 0.0 && t > 0.0) {
            break;
        }

        times.push_back(t);
        heights.push_back(h);
    }

    if (heights.empty()) {
        std::cout << "Данных нет" << std::endl;
        return 1;
    }

    auto it_max = std::max_element(heights.begin(), heights.end());
    size_t idx_max = std::distance(heights.begin(), it_max);

    double max_height = *it_max;
    double time_of_max = times[idx_max];

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Максимальная высота: " << max_height << " м" << std::endl;
    std::cout << "Время: " << time_of_max << " с" << std::endl;

    return 0;
}
