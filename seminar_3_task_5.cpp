 #include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include<algorithm>
#include <numeric>

int main() {
	struct Point { double x,y,z; };
	double Vx = 30.0;
	double Vy = 20.0;
	double Vz = 40.0;
	double dt = 1.0;
	double t_max = 10.0;
	std :: vector <Point> traj;
	traj.reserve((t_max/dt)+1);//количество шагов
	for (double t=0; t <= t_max; t += dt) {
		double x = Vx * t;
		double y = Vy * t;
		double z = Vz * t;
		traj.push_back({x,y,z});
	}
	 // Заголовок таблицы
	    std::cout << std::setw(10) << "t (с)"
	              << std::setw(15) << "x (м)"
				  << std::setw(15) << "y (м)"
				  << std::setw(15) << "z (м)"
	              << std::endl;
	    std::cout << std::string(55, '-') << std::endl;

	//Вывод данных из вектора структур
	    double current_t=0.0;
	    for (size_t i = 0; i < traj.size(); i++) {
	        std::cout << std::setw(10) << std::fixed << std::setprecision(2) << current_t
	                  << std::setw(15) << std::fixed << std::setprecision(2) << traj[i].x
					  << std::setw(15) << std::fixed << std::setprecision(2) << traj[i].y
					  << std::setw(15) << std::fixed << std::setprecision(2) << traj[i].z
	                  << std::endl;
	        current_t += dt;
	    }
	return 0;
}
