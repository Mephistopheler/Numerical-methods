#pragma once
#include <iostream>
#include <math.h>
#include <iomanip>
#include <vector>
using namespace std;


double f1(double, double);
double f2(double, double);
double df1_dx1(double, double);
double df1_dx2(double, double);
double df2_dx1(double, double);
double df2_dx2(double, double);
vector<vector<double>>& Jcobian(double, double, vector < vector <double >>&);
vector<vector<double>>& JcobianCalculation(double, double, vector < vector <double >>&, double);
int FindMaxElementInColumn(const vector < vector < double >>&, int, int);
void SwapRows(vector < vector < double >>&, int, int, int);
vector<double> GaussElimination(vector < vector < double >>&, int);
void SolveNewtonsMethod(double, double, const double, const double, const double, const int);
