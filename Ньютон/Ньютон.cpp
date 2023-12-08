#include "newton_func.h"

int main() {
    const double eps = pow(10, -9);

    const int NIT = 100;

    double x1 = 1, x2 = 1;

    double M1 = 0.01;    double M2 = 0.05;    double M3 = 0.1;
    SolveNewtonsMethod(x1, x2, eps, eps, NULL, NIT);
    SolveNewtonsMethod(x1, x2, eps, eps, M1, NIT);
    SolveNewtonsMethod(x1, x2, eps, eps, M2, NIT);
    SolveNewtonsMethod(x1, x2, eps, eps, M3, NIT);
    return 0;
}