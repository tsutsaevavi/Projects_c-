 //============================================================================
// Name        : first.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<iomanip>
using namespace std;

int main() {
	const double g = 9.81; 
	double m, L, D, T,a, a_y ;
	
	cout << "Введите m, L, D, T" << endl; // prints !!!Hello World!!!
	cin>>m>>L>>D>>T;
	a=(T-D)/m;
	cout<<"Ускорение по направлению движения "<<a<<endl;
	a_y=(L-m*g)/m;
	cout<<"вертикальное ускорение  "<< a_y<<endl;
	return 0;
}
