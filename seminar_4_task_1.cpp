#include<iostream>
using namespace std;
class Sensor{
private:
	double signalStrength; // сила сигнала (в дБ)
	bool isActive; // состояние датчика
public:
	//Конструктор
	Sensor(double strength)
	:signalStrength(strength),isActive(true){}

	void activate(){//включение датчика
		isActive = true;
	}
	void deactivate(){//включение датчика
			isActive = false;
		}


	//сеттер для signalStrengt
	void setSignalStrength(double s){
		if (s > 0)
			signalStrength = s;
		 else
			signalStrength = 0;

	}
	//геттер для signalStrengt
		double getsignalStrength() const{
			return signalStrength;
		}

	void printStatus() const{
		if (isActive){
			cout<< "Датчик активен | Сила сигнала: " << signalStrength << " дБ" << endl;
		}else {
            cout << "Датчик выключен | Сила сигнала: " << signalStrength << " дБ" << endl;
        }
	}


};
int main() {
    // Проверка из примера
    Sensor s1(45.5);
    s1.printStatus();

    s1.setSignalStrength(-10);
    s1.printStatus();

    s1.deactivate();
    s1.printStatus();

    return 0;
}
