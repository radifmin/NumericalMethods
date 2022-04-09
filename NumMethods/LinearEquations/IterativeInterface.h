#pragma once
#include "stdafx.h"

namespace Linear
{
	namespace IterativeInterface
	{
		class Tridiagonal
		{
		protected:
			Matrix mtx;
			Vector y;

			Vector alphas;
			Vector bettas;

		public:

			void InitializeMatrix()
			{
				for (int i = 0; i < n; i++)
					for (int j = 0; j < n; j++)
						mtx[i][j] = 0.0;
				double ai = 0.0;
				double ci = a(0) + a(1) + h * h * g(0);
				double bi = a(1);
				if (n > 2)
				{
					alphas[0] = bi / ci;
					bettas[0] = (f(0) * h * h) / ci;
					mtx[0][0] = ai;
					mtx[0][1] = ci;
					mtx[0][2] = bi;
				}
				else return;

				for (int i = 1; i < n - 1; i++)
				{
					double ai = alphas[i - 1] * a(i);
					double ci = a(i) + a(i + 1) + h * h * g(i);
					double bi = a(i + 1);

					mtx[i][i - 1] = ai;
					mtx[i][i] = ci;
					mtx[i][i + 1] = bi;

					alphas[i] = bi / (ci - ai);
					bettas[i] = (f(i) * h * h + bettas[i - 1] * a(i)) / (ci - ai);
				}

				ai = alphas[n - 2] * a(n - 1);
				ci = a(n - 1) + a(n) + h * h * g(n - 1);
				bi = 0.0;
				alphas[n - 1] = bi / (ci - ai);
				bettas[n - 1] = (f(n - 1) * h * h + bettas[n - 2] * a(n - 1)) / (ci - ai);
				mtx[n - 1][n - 3] = ai;
				mtx[n - 1][n - 2] = ci;
				mtx[n - 1][n - 1] = bi;
			}

			virtual const Matrix& getMatrix() const = 0;

			virtual const Vector& getAlphas() const = 0;
			virtual const Vector& getBettas() const = 0;

			virtual const Vector& getSolutions() = 0;
		};
	} // IterativeInterface
} // Linear
