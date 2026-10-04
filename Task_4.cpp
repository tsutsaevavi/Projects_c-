
#include <iostream>
#include <cmath>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	double t, h, a_y;
	cout<<" Введите h"<<endl;
	cin>>h;
	cout<<"Введите a_y"<<endl;
	cin>>a_y;
	if (a_y<=0 || h<= 0){
		cout<<"Ошибка! a_y>0 и h>0"<<endl;
		return 1;
	}
	t=sqrt(2*h/a_y);
	cout<<"t="<<t;

	return 0;
}


