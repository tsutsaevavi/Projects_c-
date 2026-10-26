#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

int main() {
    std::vector<double> x_coords = {15.5, 10.2, 15.5, 30.0, 10.2, 45.8, 30.0, 12.1, 45.8};

    std::sort(x_coords.begin(), x_coords.end());

    auto new_end = std::unique(x_coords.begin(), x_coords.end());
    x_coords.erase(new_end, x_coords.end());

    std::cout << "Итоговый вектор без дубликатов: ";
    std::cout << std::fixed << std::setprecision(1);
    for (double x : x_coords) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
