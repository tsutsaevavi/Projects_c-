//============================================================================
// Name        : 06_09.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double s, v, p, Cl, L;
	cout << "Введите s, v, p, Cl, L" << endl;
	cin >> s >> v >> p >> Cl;
	L = 0.5 * p * v*v * s * Cl;
	cout << L << endl;
	return 0;

}
