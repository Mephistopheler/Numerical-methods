#include <iostream>
#include <vector>
#include <cmath>
#include "gauss_elimination.h"

using namespace std;


std::vector<double> get_powerX(std::vector<double>& Xi, int M, int N) {
    std::vector<double> powerX(2 * M + 1);
    powerX[0] = 1;
    for (int k = 1; k <= 2 * M; k++) {
        double sum = 0;
        for (int i = 0; i < N; i++) {
            sum += pow(Xi[i], k);
        }
        powerX[k] = sum;
    }
    return powerX;
}

std::vector<std::vector<double>> get_sumX(std::vector<double>& powerX, int M) {
    std::vector<std::vector<double>> sumX(M + 1, std::vector<double>(M + 1));
    sumX[0][0] = 1;
    for (int l = 1; l <= M + 1; l++) {
        for (int j = 1, k = l + j - 2; j <= M + 1; j++, k = l + j - 2) {
            sumX[l - 1][j - 1] = powerX[k];
        }
    }
    return sumX;
}

std::vector<double> get_praw(std::vector<double>& Xi, std::vector<double>& Yi,  int M, int N) {
    std::vector<double> praw(M + 1);
    for (int l = 0; l < M + 1; l++) {
        double sum = 0;
        for (int i = 0; i < N; i++) {
            sum += Yi[i] * pow(Xi[i], l);
        }
        praw[l] = sum;
    }
    return praw;
}





int main() {
    const int N = 7;
    const int M = 1;

    std::vector<double> Yi{ 76.30, 77.80, 79.75, 80.80, 82.35, 83.90, 85.0 };
    std::vector<double> Xi{ 19.10, 25.0, 30.10, 36.0, 40.0, 45.10, 50.0};

    std::vector<double> powerX = get_powerX(Xi, M, N);
    std::vector<std::vector<double>> sumX = get_sumX(powerX, M);
    std::vector<double> praw = get_praw(Xi, Yi, M, N);


    const size_t row_ = sumX.size();
    const size_t column_ = sumX[0].size() + 1;

    std::vector<std::vector<double>> matrix(row_, vector <double> (column_));

    //double matrix[row_][column_];
    for (int i = 0; i < row_; i++) {
        for (int j = 0; j < column_ - 1; j++) {
            matrix[i][j] = sumX[i][j];
        }
    }
    for (int i = 0; i < row_; i++) {
        matrix[i][column_ - 1] = praw[i];
    }

    auto coefficients = GaussElimination(matrix, int(row_));

    for(int i = 0; i < row_; i++) {
        std::cout << coefficients[i] << ' ';
    }

    double S = 1.0 / (N - M - 1);
    double sum = 0;
    for (int i = 0; i < N; i++) {
        double dif = Yi[i] - coefficients[0];
        for (int j = 1; j < M; j++) {
            dif -= coefficients[j] * pow(Xi[i], j);
        }
        sum += pow(dif, 2);
    }
    S += sum;

    double deviation = sqrt(S);


    return 0;
}