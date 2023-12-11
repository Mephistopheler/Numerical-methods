#pragma once
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

double f(double);
double f(double, double);
double TrapezoidRule(double, double, int, double);
double SimpsonRule(double, double, int, double);
double SimpsonRule(double, double, double, double, int, int, double);
