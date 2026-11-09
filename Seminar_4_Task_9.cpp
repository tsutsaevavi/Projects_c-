#include<iostream>
using namespace std;
class AutonomousControl {
private:

	double altitude;
	double thrust;
	double targetAltitude;
public:
	//Конструктор
	AutonomousControl(double a, double t, double ta)
		:altitude(a), thrust(t),  targetAltitude(ta){}
	void updateControl() {
		if (altitude > targetAltitude) {
			thrust += 100;
		}
		else { thrust -= 100; }
	}
	void simulateStep(double dt) {
		altitude += thrust * dt / 500;
	}
	void printStatus() const {
		cout << "Высота: " << altitude << "Тяга: " << thrust << endl;
	}
};
int main() {
	std::setlocale(LC_ALL, "Russian");
	 
	AutonomousControl ac(0, 2000, 5000);
	for (int i = 0; i < 5; ++i) {
		ac.updateControl();
		ac.simulateStep(1.0);
		ac.printStatus();
	}
	return 0;
}
