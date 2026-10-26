#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <numeric>

int main() {

    std::vector<double> times1 =   {0.00, 1.00,  2.00,  3.00,   4.00,   5.00,   6.00,   7.00,   8.00,  9.00,  10.00, 11.00};
    std::vector<double> heights1 = {0.00, 45.10, 80.40, 105.90, 121.60, 127.50, 123.60, 109.90, 86.40, 53.10, 10.00, -23.30};

    std::vector<double> times2 =   {0.00, 1.00,  2.00,  3.00,   4.00,   5.00,   6.00,   7.00,   8.00,  9.00};
    std::vector<double> heights2 = {0.00, 55.00, 98.00, 129.00, 142.00, 140.00, 110.00, 72.00, 15.00, -30.00};

    std::cout << std::fixed << std::setprecision(2);

    auto it_max1 = std::max_element(heights1.begin(), heights1.end());
    double max1 = *it_max1;
    size_t idx_max1 = std::distance(heights1.begin(), it_max1);
    double t_max1 = times1[idx_max1];


    auto it_fall1 = std::find_if(heights1.begin() + 1, heights1.end(), [](double h) { return h <= 0.0; });
    double t_fall1;
    if (it_fall1 == heights1.end()) {
        t_fall1 = times1.back();
    } else {
        size_t idx_fall1 = std::distance(heights1.begin(), it_fall1);
        t_fall1 = times1[idx_fall1];
    }

    auto it_max2 = std::max_element(heights2.begin(), heights2.end());
    double max2 = *it_max2;
    size_t idx_max2 = std::distance(heights2.begin(), it_max2);
    double t_max2 = times2[idx_max2];


    auto it_fall2 = std::find_if(heights2.begin() + 1, heights2.end(), [](double h) { return h <= 0.0; });
    double t_fall2;
    if (it_fall2 == heights2.end()) {
        t_fall2 = times2.back();
    } else {
        size_t idx_fall2 = std::distance(heights2.begin(), it_fall2);
        t_fall2 = times2[idx_fall2];
    }

    std::cout << std::setw(15) << "Параметр"
              << std::setw(15) << "Ракета 1"
              << std::setw(15) << "Ракета 2" << std::endl;
    std::cout << std::string(45, '-') << std::endl;

    std::cout << std::setw(15) << "max_height"  << std::setw(15) << max1   << std::setw(15) << max2   << std::endl;
    std::cout << std::setw(15) << "time_of_max"  << std::setw(15) << t_max1 << std::setw(15) << t_max2 << std::endl;
    std::cout << std::setw(15) << "time_of_fall" << std::setw(15) << t_fall1 << std::setw(15) << t_fall2 << std::endl;
    std::cout << std::string(45, '-') << std::endl;


    if (max1 > max2) {
        std::cout << "Ракета 1 поднялась выше." << std::endl;
    } else if (max2 > max1) {
        std::cout << "Ракета 2 поднялась выше." << std::endl;
    } else {
        std::cout << "Обе ракеты поднялись на одинаковую высоту." << std::endl;
    }
    if (t_fall1 > t_fall2) {
        std::cout << "Ракета 1 находилась в воздухе дольше." << std::endl;
    } else if (t_fall2 > t_fall1) {
        std::cout << "Ракета 2 находилась в воздухе дольше." << std::endl;
    } else {
        std::cout << "Обе ракеты находились в воздухе одинаковое время." << std::endl;
    }

    return 0;
}
