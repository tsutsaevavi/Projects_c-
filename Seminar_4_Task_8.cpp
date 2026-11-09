#include<iostream>
using namespace std;
class NavigationSystem {
private:
	
	double x, y;// —текущие координаты
	double velocityX, velocityY; // проекции скорости
	bool gpsAvailable;
public:
	//Конструктор
	NavigationSystem(double x_, double y_, double vX, double vY, bool gps )
		:x(x_), y(y_), velocityX (vX), velocityY(vY), gpsAvailable(gps){}
	void integratePosition(double dt) {
		 
		x += velocityX * dt;
		y += velocityY * dt;
		
	}
	void correctGPS(double realX, double realY) {
		if (gpsAvailable == true) {
			x = (realX + x) / 2;
			y = (realY + y) / 2;
		}
	}
		void printPosition() {
			cout << " Скорректированные координаты: (" << x << ", " << y << ") "<< endl;
		}

	
	

};
int main() {
	std::setlocale(LC_ALL, "Russian");
	NavigationSystem nav(0, 0, 100, 50, true);
	nav.integratePosition(1);
	nav.correctGPS(110, 60);
	nav.printPosition();
	return 0;
}
