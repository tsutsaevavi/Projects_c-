#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

int main() {
    std::vector<double> accel_data = {0.0, 9.8, 12.4, 0.0, 15.1, 0.0, 8.2, 0.0, 0.0, 9.8};

    long long zero_count = std::count(accel_data.begin(), accel_data.end(), 0.0);

    std::cout << "Количество нулевых показаний: " << zero_count << std::endl;

    return 0;
}
