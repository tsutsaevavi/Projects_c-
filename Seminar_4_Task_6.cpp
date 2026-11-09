#include<iostream>
using namespace std;
class RocketStage {
private:
	double thrust;// — тяга(Н)
	double burnTime;// — время работы(с)
	double mass;// — масса ступени(кг)
public:
	RocketStage(double t, double b, double m)
		:thrust(t), burnTime (b), mass (m) {}
	double getDeltaV() const {
		return (thrust * burnTime) / mass;
		 

	}
	void printInfo() const {
		std::setlocale(LC_ALL, "Russian");
		cout << " Итоговая скорость ракты: " << getDeltaV() << endl;

	}
	
};
int main() {
	std::setlocale(LC_ALL, "Russian");
	RocketStage s1(5000, 10, 1000);
	RocketStage s2(7000, 8, 900);
	RocketStage s3(9000, 6, 800);
	double totalV = s1.getDeltaV() + s2.getDeltaV() + s3.getDeltaV();
	std::cout << "Итоговая скорость ракеты: " << totalV << " м/с\n";
}
