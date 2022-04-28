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
				Vector p;
				int k = 0;
				do {
					for (int i = 0; i < n; i++)
						p[i] = y[i];
					for (int i = 1; i < n - 1; i++)
					{
						double var = 0.0;
						for (int j = 1; j < n - 1; j++)
							if (j != i) var += mtx[i][j] * y[j];
						y[i] = (f(i) * h * h) / mtx[i][i];
					}
					k++;
				} while (!converge(p));
				std::cout << "iterations: " << k << '\n';
				return y;
				/*Vector temp;
				double norm = 0.0;

				do {
					for (int i = 1; i < n - 1; i++)
					{
						temp[i] = f(i) * h * h;
						for (int j = 1; j < n - 1; j++)
							if (j != i) temp[i] += (mtx[i][j] * y[j]);

						y[i] = (f(i) * h * h - temp[i]) / mtx[i][i];
					}
					norm = fabs(y[0] - temp[0]);
					for (int k = 1; k < n - 1; k++) {
						if (fabs(y[k] - temp[k]) > norm)
							norm = fabs(y[k] - temp[k]);
						y[k] = temp[k];
					}
				} while (norm > EPS);

				return y;*/

				/*Vector temp;
				do
				{
					for (int i = 1; i < n - 1; i++)
					{
						double var = 0.0;
						for (int j = 1; j < n - 1; j++)
							if (j != i) var += (mtx[i][j] * y[j]);

						y[i] = (f(i)*h*h - var) / mtx[i][i];
					}
				} while (!converge(temp));
				return y;*/
			}
			bool converge(const Vector& xkp)
			{
				double norm = 0.0;
				for (int i = 1; i < n - 1; i++)
					norm += (y[i] - xkp[i]) * (y[i] - xkp[i]);
				return (std::sqrt(norm) < EPS);
			}
			double okr(double x)
			{
				int i = 0;
				double neweps = EPS;
				while (neweps < 1)
				{
					i++;
					neweps *= n;
				}
				int okr = std::pow(double(n), i);
				x = int(x * okr + 0.5) / double(okr);

				return x;
			}
		};
	} // ConcreteIterative
} // Linear
