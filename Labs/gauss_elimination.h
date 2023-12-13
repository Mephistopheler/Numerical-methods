#ifndef APPROXIMATION_GAUSS_H
#define APPROXIMATION_GAUSS_H
#include <cmath>
#include <iostream>

using namespace std;

int FindMaxElementInColumn(const vector < vector < double >>& matrix, int column, int n) {
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
void SwapRows(vector < vector < double >>& matrix, int row1, int row2, int n) {
    for (int i = 0; i <= n; i++) {
        swap(matrix[row1][i], matrix[row2][i]);
    }
}
vector <double> GaussElimination(vector < vector < double >>& matrix, int n) {
    for (int i = 0; i < n; i++) {
        int maxRow = FindMaxElementInColumn(matrix, i, n);
        SwapRows(matrix, i, maxRow, n);
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
#endif //APPROXIMATION_GAUSS_H
