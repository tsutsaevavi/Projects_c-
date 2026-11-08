#include<iostream>
using namespace std;
class Trajectory {
private:
	double startX, startY; //— координаты старта
	double angle;// — угол подъёма (в градусах)
public:
	//конструктор все рараметры = 0
	Trajectory()
	:startX(0),startY(0), angle(0){}
	//конструктор с ненулевыми параметрами
	Trajectory(double X,double Y, double ang)
		:startX(X),startY(Y), angle(ang){}

	void printTrajectory() const{
		cout<<"Старт:("<<startX<<","<<startY<<"), угол "<<angle<<endl;
	}

};
int main() {
    // Проверка из примера
	Trajectory t1;
	 Trajectory t2(100, 200, 45);

	    t1.printTrajectory();
	    t2.printTrajectory();



    return 0;
}
