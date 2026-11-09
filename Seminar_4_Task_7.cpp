#include<iostream>
using namespace std;
class FlightComputer {
private:
	double altitude;
	double velocity;
	double fuel;
	double thrust;
	double currentTime;

public:
	FlightComputer(double a, double v, double f, double t)
		:altitude(a), velocity(v), fuel(f), thrust(t){}
	void simulateStep(double dt)  {
		if (fuel > 0) {
			velocity += (thrust / 100) - 9.8 * dt;
			fuel -= dt * 2;
		}
		if (fuel < 0) {
			fuel = 0;
		}
		else {
			velocity += -9.8 * dt;
		}

		altitude += velocity * dt;
		if (altitude < 0) {
			altitude = 0;
			velocity = 0;
		}
		currentTime += dt;
	}
	void printStatus() const {
		cout<<"t = "<< currentTime << " c, "<< "Высота = " << altitude << "м/с, " 
			<< "скорость=" << velocity << "м/с, "
			<< "топливо=" << fuel << " л " << std::endl;
	
	}
};
int main() {

	std::setlocale(LC_ALL, "Russian");


	FlightComputer fc(0.0, 0.0, 100.0, 12000.0);

	for (int i = 0; i < 5; i++) {
		fc.simulateStep(0.5);
		fc.printStatus();


		return 0;
	}
}
