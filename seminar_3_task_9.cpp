#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

int main() {
    std::vector<double> h = {0.00, 48.50, 78.10, 108.90, 119.20, 131.50, 120.10, 112.40, 84.20, 56.80, 10.00};
    size_t n = h.size();

    std::vector<double> smoothed(n);

    if (n < 3) {
        std::cout << "Вектор слишком мал для сглаживания окном из 3 элементов!" << std::endl;
        return 1;
    }


    for (size_t i = 1; i + 1 < n; ++i) {
        smoothed[i] = (h[i - 1] + h[i] + h[i + 1]) / 3.0;
    }


    smoothed[0] = h[0];
    smoothed[n - 1] = h[n - 1];


    std::cout << std::setw(15) << "Исходная h"
              << std::setw(18) << "Сглаженная h" << std::endl;
    std::cout << std::string(33, '-') << std::endl;

    std::cout << std::fixed << std::setprecision(2);
    for (size_t i = 0; i < n; ++i) {
        std::cout << std::setw(15) << h[i]
                  << std::setw(18) << smoothed[i] << std::endl;
    }
    std::cout << std::string(33, '-') << std::endl;

    double sum_sq_diff = 0.0;
    for (size_t i = 0; i < n; ++i) {
        double diff = h[i] - smoothed[i];
        sum_sq_diff += diff * diff;
    }
    double mse = sum_sq_diff / n;
    std::cout << "Среднеквадратичное отклонение (MSE): " << mse << std::endl;

    return 0;
}
