#pragma once
#include "stdafx.h"

namespace Linear
{
	namespace ConcreteIterative
	{
		class Jacobi : IterativeInterface::Tridiagonal
		{
		public:
			Jacobi()
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
				Vector r;
				Vector temp;
				double norm = 0.0;
				int k = 0;
				do {
					for (int i = 1; i < n - 1; i++)
					{
						double ai = mtx[i][i - 1];
						double ci = mtx[i][i];
						double bi = mtx[i][i + 1];
						y[i] = (a(i) * temp[i - 1] + a(i + 1) * temp[i + 1] + f(i) * h * h) / (mtx[i][i]);
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
