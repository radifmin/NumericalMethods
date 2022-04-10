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

				do {
					for(int i = 1; i < n-1; i++) {
						temp[i] = f(i) * h * h;
						for (int g = 1; g < n-1; g++) {
							if (i != g)
								temp[i] -= mtx[i][g] * y[g];
						}
						temp[i] /= mtx[i][i];
					}
					norm = fabs(y[0] - temp[0]);
					for (int h = 1; h < n-1; h++) {
						if (fabs(y[h] - temp[h]) > norm)
							norm = fabs(y[h] - temp[h]);
						y[h] = temp[h];
					}
				} while (norm > EPS);

				return y;
			}
		};
	} // ConcreteIterative
} // Linear
