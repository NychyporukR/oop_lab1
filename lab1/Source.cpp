#include "Math.h"
#include "application.h"
#include <iostream>
#include <iomanip> //  бібліотека для форматування виводу
using namespace std;

int main() {
    double x, y, z;
    x = 0.48 * 13;
    y = 0.47 * 13;
    z = -1.32 * 13;

    application calc;

    calc.Fn_b(x, y, z);
    calc.Fn_a(x, y, z);

    double a = calc.geta();
    cout << "The value of a : " << a << endl;
    double b = calc.getb();
    cout << "The value of b : " << b << endl;

    int x_s = -1;
    int x_e = 1;
    double dx = 0.2;

    cout << "\t\t+-------+-------+-------" << endl;
    cout << "\t\t |   x   |   a   |   b   " << endl;
    cout << "\t\t+-------+-------+-------" << endl;

    for (double x = x_s; x < x_e; x += dx) {
        calc.Fn_b(x, y, z);
        calc.Fn_a(x, y, z);

        
        double a = calc.geta();
        double b = calc.getb();

        // setw(6) - фіксована ширина
        cout << "\t\t| " << setw(6) << x << " | " << setw(6) << a << " | " << setw(6) << b << " |" << endl;
    }

    cout << "\t\t+-------+-------+-------" << endl;

    return 0;
}


void application::Fn_b(double x, double y, double z)
{
	b = pow(cos(atan((pow(x, 3) + y) / (1 + pow(abs(z), 0.5)))), 2) + y * exp(-(3 * z - y) / (z + x));

}

void application::Fn_a(double x, double y, double z)
{
	double a1 = 1 + pow(pow(sin(pow(abs(x + y), 0.3)), 2), 1. / 2);
	double a2 = 0.3 + pow(b, 2) + pow(sin(pow(abs(z), 1.3)), 2);
	double a3 = tan(3 * x / z);
	a = a1 / a2 + a3;
}

