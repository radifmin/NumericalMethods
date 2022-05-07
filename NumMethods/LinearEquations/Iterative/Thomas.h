#pragma once
#include "stdafx.h"

namespace Linear
{
	namespace ConcreteIterative
	{
		class Thomas : IterativeInterface::Tridiagonal
		{
		public:
			Thomas()
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
				y[n - 1] = 0.0;
				y[0] = 0.0;
				for (int i = n - 2; i > 0; i--) {
					y[i] = alphas[i] * y[i + 1] + bettas[i];
				}

				return y;
			}
		};
	} // ConcreteIterative
} // Linear
