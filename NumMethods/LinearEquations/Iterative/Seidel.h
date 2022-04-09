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
				// ...
				return y;
			}
		};
	} // ConcreteIterative
} // Linear
