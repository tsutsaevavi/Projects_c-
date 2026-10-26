#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

int main() {
    std::vector<double> temp_data = {85.0, -150.0, 92.5, 250.0, 110.0, -120.0, 95.0, 300.0, 88.0};

    auto new_end = std::remove_if(temp_data.begin(), temp_data.end(), [](double t) {
        return t < -100.0 || t > 200.0;
    });

    temp_data.erase(new_end, temp_data.end());

    std::cout << "Очищенные показания температуры: ";
    for (double t : temp_data) {
        std::cout << std::fixed << std::setprecision(1) << t << " ";
    }
    std::cout << std::endl;

    return 0;
}
