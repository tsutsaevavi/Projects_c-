#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <iomanip>

int main() {
    std::vector<double> y_coords = {0.0, 45.1, 80.4, 105.9, 121.6, 127.5, 123.6, 109.9, 86.4, 53.1, 10.0};

    std::vector<double> diffs(y_coords.size());
    std::adjacent_difference(y_coords.begin(), y_coords.end(), diffs.begin());

    double total_path = std::accumulate(diffs.begin() + 1, diffs.end(), 0.0, [](double sum, double diff) {
        return sum + std::abs(diff);
    });

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Суммарный путь ракеты: " << total_path << " м" << std::endl;

    return 0;
}
