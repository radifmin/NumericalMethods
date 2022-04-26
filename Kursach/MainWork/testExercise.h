#pragma once
#include "stdafx.h"
class Tumor
{
protected:
	std::array<double,n> y1;
	std::array<double,n> y2;
public:
	std::pair<std::array<double,n>,std::array<double,n>>get_Solutions()
	{
		print(y1, 1);
		print(y2, 2);
		return std::make_pair(y1,y2);
	}

	void print(std::array<double,n> y, int number)
	{
		std::cout << "y"<< number<<": "<< y[0];
		for (int i = 1; i < n; i++)
		{
			std::cout << y[i] << " ";
		}
		std::cout << '\n';
	}
	void Solute()
	{
		double t0 = 0.0;
		for (int i = 0; i < n - 1; i++)
		{
			y1[i + 1] = y1[i] + (k11(t0, y1[i], y2[i]) + k12(t0, y1[i], y2[i])) * h / 2.0;
			y2[i + 1] = y2[i] + (k21(t0, y1[i], y2[i]) + k22(t0, y1[i], y2[i])) * h / 2.0;
		}
	}
};