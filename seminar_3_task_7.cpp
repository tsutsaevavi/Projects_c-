#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <numeric>

int main() {
    std::vector<double> times =   {0.00, 1.00,  2.00,  3.00,   4.00,   5.00,   6.00,   7.00,   8.00,  9.00,  10.00, 11.00};
    std::vector<double> heights = {0.00, 45.10, 80.40, 105.90, 121.60, 127.50, 123.60, 109.90, 86.40, 53.10, 10.00, -23.30};

    std::cout << std::fixed << std::setprecision(2);


    auto it = std::find_if(heights.begin() + 1, heights.end(), [](double h){
        return h <= 0.0;
    });

    if (it == heights.end()) {
        std::cout << "Падения не было ." << std::endl;
    } else {
        size_t idx = std::distance(heights.begin(), it);
        double t_fall = times[idx];

        std::cout << "Ракета упала на землю" << std::endl;
        std::cout << "Индекс элемента: " << idx << std::endl;
        std::cout << "Момент времени t_fall = " << t_fall << " с." << std::endl;
        std::cout << "Высота в этот момент: " << heights[idx] << " м" << std::endl;
    }

    return 0;
}

