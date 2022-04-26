#pragma once
#include"stdafx.h"
const double h = 0.1;
const size_t n = 2;
double f1(double t, double y1, double y2)
{
	return (y1 / (2 + 2 * t) - 2 * t * y2);
}
double f2(double t, double y1, double y2)
{
	return (y2 / (2 + 2 * t) + 2 * t * y1);
}
double k11(double t, double y1, double y2)
{
	return f1(t, y1, y2);
}
double k12(double t, double y1, double y2)
{
	return f2(t, y1, y2);
}
double k21(double t, double y1, double y2)
{
	return f1(t + y1 * h / 3, y1 + h * k11(t, y1, y2) / 3, y2 + h * k12(t, y1, y2) / 3);
}
double k22(double t, double y1, double y2)
{
	return f1(t + y1 * h / 3, y1 + h * k11(t, y1, y2) / 3, y2 + h * k12(t, y1, y2) / 3);
}
double y1(double t)
{
	return cos(std::pow(t, 2)) * sqrt(1 + t);
}
double y2(double t)
{
	return sin(std::pow(t, 2)) * sqrt(1 + t);
}
