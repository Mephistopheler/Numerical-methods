#include "Newton.h"

int main() {
    const double eps = pow(10, -9);

    const int NIT = 100;

    double x1 = 1, x2 = 1;

    double M1 = 0.01;    double M2 = 0.05;    double M3 = 0.1;
    solveNewtonsMethod(x1, x2, eps, eps, NULL, NIT);
    solveNewtonsMethod(x1, x2, eps, eps, M1, NIT);
    solveNewtonsMethod(x1, x2, eps, eps, M2, NIT);
    solveNewtonsMethod(x1, x2, eps, eps, M3, NIT);
    return 0;
}