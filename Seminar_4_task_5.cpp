#include<iostream>
using namespace std;
class  Autopilot {
private:
	double courseAngle;// — курс(°)
	double altitude; //— высота(м)
public:
	Autopilot(double A, double h)

		:courseAngle(A), altitude(h) {
	}
	void changeCourse(double delta) {
		courseAngle += delta;
	}
	void changeAltitude(double delta) {
		altitude += delta;

	}

	void printStatus() const { 
	std::setlocale(LC_ALL, "Russian");
	cout << " Курс " << courseAngle << endl;
		
	
	cout << " Высота " << altitude << endl;
		
	}

};
int main() {
	Autopilot a1(90, 1000);
	a1.changeCourse(10);
	a1.changeAltitude(500);
	a1.printStatus();
	return 0;
}
