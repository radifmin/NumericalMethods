#pragma once
#include "stdafx.h"

namespace Linear
{
	namespace ConcreteIterative
	{
		class Seidel : IterativeInterface::Tridiagonal
		{
		public:
			Seidel()
			{
				InitializeMatrix();
			}

			virtual const Matrix& getMatrix() const override
			{
				return mtx;
			};

			virtual const Vector& getAlphas() const override
			{
				return alphas;
			}
			virtual const Vector& getBettas() const override
			{
				return bettas;
			}

			virtual const Vector& getSolutions() override
			{
				Vector temp;
				Vector r;
				int k = 0;
				do {
					for (int i = 1; i < n - 1; i++)
					{
						y[i] = (a(i) * y[i - 1] + a(i + 1) * temp[i + 1] + f(i) * h * h) / mtx[i][i];
					}
					r = temp - y;
					temp = y;
					k++;
				} while (abs(r) > EPS);
				std::cout << "iterations: " << k << '\n';
				return y;
			}
		};
	} // ConcreteIterative
} // Linear
