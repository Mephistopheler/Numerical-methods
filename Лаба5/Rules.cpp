#include "Rules.h"

using namespace std;

double f(double x) {
    return pow(M_E, x / 2) / pow(x + 1, 1 / 2);
}

double f(double x, double y) {
    return (pow(x, 2)) / (1 + pow(y, 2));
}

double TrapezoidRule(double a, double b, int n, double e) {
    double dx, sum, Result = 0, ResultPrev;
    do {
        ResultPrev = Result;
        dx = 1 * (b - a) / n;
        sum = 0.5 * (f(a) + f(b));
        for (int i = 1; i < n; i++) {
            sum += f(a + i * dx);
        }
        Result = sum * dx;
        n *= 2;
    } while (fabs(Result - ResultPrev) > 3 * e);
    return Result;
}

double SimpsonRule(double a, double b, int n, double e) {
    if (n % 2 != 0) {
        cout << "Error";
        exit(0);
    }
    double dx, sum, Result = 0, ResultPrev;
    do {
        ResultPrev = Result;
        dx = (b - a) / n;
        sum = f(a) + f(b);
        for (int i = 1; i < n; i += 2) {
            sum += f(a + i * dx) * 4;
        }
        for (int i = 2; i < n; i += 2) {
            sum += f(a + i * dx) * 2;
        }
        Result = dx / 3 * sum;
        n *= 2;
    } while (fabs(Result - ResultPrev) > 15 * e);
    return Result;
}

double SimpsonRule(double a, double b, double c, double d, int m, int n, double e) {
    if (n % 2 != 0 || m % 2 != 0) {
        cout << "Error";
        exit(0);
    }
    double dx = (b - a) / (2 * n);
    double dy = (d - c) / (2 * m);
    double sum = 0;
    double Result = 0;
    double ResultPrev;

    do {
        ResultPrev = Result;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sum += f(a + (2 * i * dx), c + (2 * j * dy));
                sum += 4 * f(a + ((2 * i + 1) * dx), c + (2 * j * dy));
                sum += f(a + ((2 * i + 2) * dx), c + (2 * j * dy));
                sum += 4 * f(a + (2 * i * dx), c + ((2 * j + 1) * dy));
                sum += 16 * f(a + ((2 * i + 1) * dx), c + ((2 * j + 1) * dy));
                sum += 4 * f(a + ((2 * i + 2) * dx), c + ((2 * j + 1) * dy));
                sum += f(a + (2 * i * dx), c + ((2 * j + 2) * dy));
                sum += 4 * f(a + ((2 * i + 1) * dx), c + ((2 * j + 2) * dy));
                sum += f(a + ((2 * i + 2) * dx), c + ((2 * j + 2) * dy));
            }
        }
        Result = sum * (dx * dy / 9);
        sum = 0;
    } while (fabs(Result - ResultPrev) > 15 * e);
    return Result;
}