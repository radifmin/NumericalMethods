#pragma once
#include "stdafx.h"

namespace Linear
{
	namespace ConcreteIterative
	{
		class DownRelaxation : public IterativeInterface::Tridiagonal
		{
		public:
			DownRelaxation()
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
				double w = 0.0;
				double norm = 0.0;
				Vector temp;
				int k = 0;
				do
				{
					for (int i = 1; i < n - 1; i++)
					{
						y[i] = f(i) * h * h;
						for (int j = 1; j < n - 1; j++)
						{
							if (i != j)
								y[i] = y[i] - mtx[i][j] * y[j];
						}
						y[i] /= mtx[i][i];
						y[i] = w * y[i] + (1 - w) * temp[i];
						w += 1.0 / n;
						if (fabs(y[i] - temp[i]) > norm)
							norm = fabs(y[i] - temp[i]);
						temp[i] = y[i];
					}
					k++;
				} while (norm < EPS);
				std::cout << "iterations: " << k << '\n';
				return y;
			}
		};
	} // Linear
} // ConcreteIterative
