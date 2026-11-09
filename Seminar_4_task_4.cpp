#include<iostream>
using namespace std;
class Gyroscope {
private:
	double angularVelocity;
	bool calibrationRequired;
public:
	Gyroscope(double V, double C)
		:angularVelocity(V), calibrationRequired(C) {}
	void calibrate() { //сброс флага калибровки
		calibrationRequired = false;
	

	}
	void printStatus() const{// вывод текущего состояния
		std::setlocale(LC_ALL, "Russian");
		if (calibrationRequired) {
			cout << "Калибровка требуется | " << angularVelocity << endl;
		}
		else {
			cout << "Калибровка не требуется | " << angularVelocity << endl;
		}
	
	}

};
 
int main() {
	Gyroscope g1(120.5, true);
	g1.printStatus();
	g1.calibrate();
		g1.printStatus();

}
