#pragma once
#include "stdafx.h"

namespace Linear
{
	namespace ConcreteIterative
	{
		class GradientDescent :IterativeInterface::Tridiagonal
		{
		public:
			GradientDescent()
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
				double t = 0.0;
				int k = 0;
				do
				{
					for (int i = 1; i < n - 1; i++)
					{
						double ai = mtx[i][i - 1];
						double ci = mtx[i][i];
						double bi = mtx[i][i + 1];

						r[i] = -ai * y[i - 1] + ci * y[i] - bi * y[i + 1] - f(i) * h * h;

						y[i] = y[i - 1] - t * r[i];
					}

					t = r * r / ((mtx * r) * r);
					//r = mtx * y - b;
					k++;
				} while (abs(r) > EPS);
				std::cout << "iterations: " << k << '\n';
				return y;
			}
		};
	} // ConcreteIterative
} // Linear
