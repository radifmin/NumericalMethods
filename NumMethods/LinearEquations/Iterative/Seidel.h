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
				return y;
			}
			bool converge(Vector xkp)
			{
				double norm = 0.0;
				for (int i = 1; i < n - 1; i++)
					norm += (y[i] - xkp[i]) * (y[i] - xkp[i]);
				return (std::sqrt(norm) > EPS);
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
