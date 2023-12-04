#include <iostream>
#include <iomanip>
#include <vector>
#include "Newton.h"
using namespace std;



double f1(double x1, double x2) {
    return (2 * x1 * x1 * x1 - x2 * x2 - 1);
}
double df1_dx1(double x1, double x2) {
    return 6 * pow(x1, 2);
}
double df1_dx2(double x1, double x2) {
    return -2 * x2;
}
double f2(double x1, double x2) {
    return (x1 * x2 * x2 * x2 - x2 - 4);
}
double df2_dx1(double x1, double x2) {
    return pow(x2, 3);
}
double df2_dx2(double x1, double x2) {
    return 3 * x1 * pow(x2, 2) - 1;
}

vector<vector<double>> Jcobian(double x1, double x2, vector < vector <double >> J)
{
    J[0][0] = df1_dx1(x1, x2);  J[0][1] = df1_dx2(x1, x2);
    J[1][0] = df2_dx1(x1, x2);  J[1][1] = df2_dx2(x1, x2);
    return J;
}
vector<vector<double>> Jcobian_calculation(double x1, double x2, vector < vector <double >> J, double M)
{
    J[0][0] = (f1(x1 + M * x1, x2) - f1(x1, x2)) / (M * x1);  J[0][1] = (f1(x1, x2 + M * x2) - f1(x1, x2)) / (M * x2);
    J[1][0] = (f2(x1 + M * x1, x2) - f2(x1, x2)) / (M * x1);  J[1][1] = (f2(x1, x2 + M * x2) - f2(x1, x2)) / (M * x2);
    return J;
}
int findMaxElementInColumn(const vector < vector < double >>& matrix, int column, int n) {
    int maxRow = column;
    double maxElement = abs(matrix[column][column]);

    for (int i = column + 1; i < n; i++) {
        if (abs(matrix[i][column]) > maxElement) {
            maxElement = abs(matrix[i][column]);
            maxRow = i;
        }
    }

    return maxRow;
}
void swapRows(vector < vector < double >>& matrix, int row1, int row2, int n) {
    for (int i = 0; i <= n; i++) {
        swap(matrix[row1][i], matrix[row2][i]);
    }
}
vector < double > gaussElimination(vector < vector < double >> matrix, int n) {
    for (int i = 0; i < n; i++) {
        int maxRow = findMaxElementInColumn(matrix, i, n);
        swapRows(matrix, i, maxRow, n);
        for (int i = 0; i < n; i++) {
            double a = matrix[i][i];
            if (abs(a) == 0) {
                cout << "No answers" << endl;
                system("pause");
            }
        }
        for (int j = i + 1; j < n; j++) {
            double factor = matrix[j][i] / matrix[i][i];
            for (int k = i; k < n + 1; k++) {
                matrix[j][k] -= factor * matrix[i][k];
            }
        }
    }
    vector < double > solution(n);
    for (int i = 0; i < n; i++) {
        solution[i] = matrix[i][n];
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            solution[i] -= matrix[i][j] * solution[j];
        }
        solution[i] /= matrix[i][i];
    }

    return solution;
}

void solveNewtonsMethod(double x1, double x2, const double E1, const double E2, const double M, const int NIT) {
    double delta1 = max(abs(f1(x1, x2)), abs(f2(x1, x2)));
    double delta2 = 1;

    cout << "Initial approximation : ( " << x1 << " ; " << x2 << " )\n";
    if (M != NULL) { cout << "Relative increment = " << M << "\n"; }

    int iter = 0;
    while ((delta1 > E1 || delta2 > E2) && iter < NIT) {
        iter++;

        cout << iter << "|\t" << "delta1| " << delta1 << "\t\t" << "delta2| " << delta2 << endl;

        vector<double> F{ f1(x1, x2), f2(x1, x2) };
        vector<vector<double>> J(2, vector<double>(2));

        if (M == NULL) {
            J = Jcobian(x1, x2, J);
        }
        else {
            J = Jcobian_calculation(x1, x2, J, M);
        }
        vector < vector < double>> matrix(2, vector<double>(3));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                matrix[i][j] = J[i][j];
            }
        }
        matrix[0][2] = -F[0];
        matrix[1][2] = -F[1];

        vector<double> solution = gaussElimination(matrix, 2);
        x1 += solution[0];
        x2 += solution[1];

        delta1 = abs(F[0]);
        for (int i = 1; i < F.size(); i++) {
            if (delta1 < abs(F[i])) {
                delta1 = abs(F[i]);
            }
        }

        double v1 = abs(x1) < 1 ? abs(solution[0]) : abs(solution[0] / x1);
        double v2 = abs(x2) < 1 ? abs(solution[1]) : abs(solution[1] / x2);
        delta2 = max(v1, v2);
    }
    cout << "\n" << iter << "|\t" << "x1| " << x1 << "\t" << "x2| " << x2 << "\n";
    cout << "///////////////////////////////////////////////////////////////////\n\n";
}




void Newton_method(double x1, double x2, int n) {

}