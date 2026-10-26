#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include<algorithm>
#include <numeric>

int main() {


	std::vector<double> heights={0.00, 45.10, 80.40, 105.90, 121.60, 127.50, 123.60, 109.90, 86.40, 53.10, 10.00};
	 std::cout << "Исходные высоты: ";
	for (double h : heights) std::cout << std::fixed << std::setprecision(2) << h << " ";
	     std::cout << "\nРазмер до удаления: " << heights.size() << "\n\n";
	     auto new_end = std::remove_if(heights.begin(), heights.end(), [](double h){
	     return h < 10.0; });
	     heights.erase(new_end, heights.end());
	     std::cout << "Высоты после удаления (все элементы < 10 м стёрты):\n";
	         if (heights.empty()) {
	        	 std::cout<<"Пусто!";

	         }
	         else {
	                 for (double h : heights) {
	                     std::cout << std::fixed << std::setprecision(2) << h << " ";
	                 }
	                 std::cout << "\nРазмер после удаления: " << heights.size() << "\n";
	             }
	         //проверка теста 1(все значения<10)

	         std::cout << "\n--- ТЕСТ 1: Все значения < 10 ---\n";
	          std::vector<double> test_all_low = {1.2, 5.5, 0.0, 9.9};

	          auto end_low = std::remove_if(test_all_low.begin(), test_all_low.end(), [](double h) { return h < 10.0; });
	          test_all_low.erase(end_low, test_all_low.end());

	          if (test_all_low.empty()) {
	              std::cout << "Тест пройден успешно: вектор стал пустым!\n";
	          }


	          //тест 2(проверка ничего не должно удалЯться)
	          std::cout << " ТЕСТ 2: --- ТЕСТ 2: Ничего не удаляется ---\n";
	          std::vector<double> test_all_high = {50.0, 100.0, 12.5};
	          size_t old_size = test_all_high.size();

	          auto end_high = std::remove_if(test_all_high.begin(), test_all_high.end(), [](double h) { return h < 10.0; });
	          test_all_high.erase(end_high, test_all_high.end());

	          if (test_all_high.size() == old_size) {
	              std::cout << "Тест пройден успешно: ни один элемент не удалён, размер сохранён.\n";
	          }

	          return 0;
}
