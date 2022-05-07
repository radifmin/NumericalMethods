#pragma once
#include "stdafx.h"

namespace Linear
{
	namespace ConcreteIterative
	{
		class UpRelaxation :public IterativeInterface::Tridiagonal
		{
		public:
			UpRelaxation()
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
				Vector best;
				int pre_k = INT32_MAX;
				double step = 1.0/10.0;
				for (double w = 1.0; w < 2.0+step; w += step)
				{
					Vector temp;
					Vector r;
					int k = 0;
					do
					{
						for (int i = 1; i < n - 1; i++)
						{
							y[i] = (1 - w) * temp[i] + w * (a(i) * y[i - 1] + a(i + 1) * temp[i + 1] + f(i) * h * h) / mtx[i][i];
						}
						r = temp - y;
						temp = y;
						k++;
					} while (abs(r) > EPS);
					// choosing the best solution
					if (k < pre_k && w>0) {
						pre_k = k;
						best = y;
					}
					std::cout << "w \t" << "k\n"
						<< w << " \t" << k << '\n'
						<< "y: " << y << "\n";
				}
				std::cout << '\n';
				return best;
			}
		};
	} // ConcreteIterative
} // Linear
