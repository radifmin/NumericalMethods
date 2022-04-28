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
				Vector temp;
				double norm = 0.0;
				int k = 0;
				do {
					for (int i = 1; i < n-1; i++) {
						temp[i] = f(i) * h * h;
						for (int j = 1; j < n-1; j++) {
							if (j != i) temp[i] -= mtx[i][j] * y[j];
						}
						temp[i] /= mtx[i][i];
					}
					norm = fabs(y[0] - temp[0]);
					for (int k = 1; k < n-1; k++) {
						if (fabs(y[k] - temp[k]) > norm)
							norm = fabs(y[k] - temp[k]);
						y[k] = temp[k];
					}
					k++;
				} while (norm > EPS);
				std::cout << "iterations: " << k << '\n';
				return y;
			}
		};
	} // ConcreteIterative
} // Linear
