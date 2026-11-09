#include<iostream>
using namespace std;
class Engine {
private:
	double thrust; // тяга (Н)
	double fuelFlow; // расход топлива (кг/с)
public:
	Engine(double T, double F)
	:thrust(T), fuelFlow(F){}
	//геттер для signalStrengt
	double  getSpecificImpulse() const{
		if ( fuelFlow <= 0){
			return 0;
		}
			return thrust/(fuelFlow*9.81);
			}
	void printInfo() const{
		cout << "Тяга: " << thrust << " Н, "
		             << "Расход топлива: " << fuelFlow << " кг/с, "
		             << "Удельный импульс: " << getSpecificImpulse() << " с" << endl;
	}

};
int main() {
    Engine e1(5000, 2.5);
    e1.printInfo();

    return 0;
}
