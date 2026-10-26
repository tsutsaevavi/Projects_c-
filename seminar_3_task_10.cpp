#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>


struct Point {
    double x, y, z;
};


class Rocket {
private:
    double x, y, z;
    double vx, vy, vz;
    const double g = 9.8;

public:

    Rocket(double start_x, double start_y, double start_z, double start_vz) {
        x = start_x;
        y = start_y;
        z = start_z;
        vz = start_vz;
        vx = 30.0;
        vy = 20.0;
    }


    void updatePosition(double dt) {

        if (z < 0.0) return;

        x += vx * dt;
        y += vy * dt;
        z += vz * dt;


        vz -= g * dt;
    }


    void changeVelocity(double new_vx, double new_vy, double new_vz) {
        vx = new_vx;
        vy = new_vy;
        vz = new_vz;
    }


    Point getPosition() const {
        return {x, y, z};
    }


    bool isFlying() const {
        return z >= 0.0;
    }
};

int main() {

    std::vector<Rocket> squad;
    squad.reserve(5);



    squad.emplace_back(1000.0, 10.0,  0.0, 50.0);
    squad.emplace_back(900.0,  15.0, -5.0, 40.0);
    squad.emplace_back(800.0,  0.0,   0.0, 60.0);
    squad.emplace_back(1100.0, -10.0, 5.0, 35.0);
    squad.emplace_back(950.0,  20.0,  0.0, 45.0);


    std::vector<std::vector<Point>> trajectories(5);

    double T = 15.0;
    double dt = 1.0;


    for (double t = 0.0; t <= T; t += dt) {

        for (size_t i = 0; i < squad.size(); ++i) {
            squad[i].updatePosition(dt);
            trajectories[i].push_back(squad[i].getPosition());
        }
    }


    std::cout << "=== Конечное положение отряда ракет (Задача 10) ===\n" << std::endl;
    std::cout << std::setw(10) << "Ракета #"
              << std::setw(15) << "Конечная X"
              << std::setw(15) << "Конечная Y"
              << std::setw(15) << "Конечная Z" << std::endl;
    std::cout << std::string(55, '-') << std::endl;

    std::cout << std::fixed << std::setprecision(2);
    for (size_t i = 0; i < squad.size(); ++i) {
        Point last_pos = squad[i].getPosition();


        double display_z = (last_pos.z < 0.0) ? 0.00 : last_pos.z;

        std::cout << std::setw(10) << (i + 1)
                  << std::setw(15) << last_pos.x
                  << std::setw(15) << last_pos.y
                  << std::setw(15) << display_z << std::endl;
    }
    std::cout << std::string(55, '-') << std::endl;

    return 0;
}
