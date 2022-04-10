#pragma once
#include "stdafx.h"

namespace UnitTests
{
	class testLinearEquation
	{
	public:
		static void testThomas()
		{
			std::cout << "******Thomas test start**********\n";

			Linear::ConcreteIterative::Thomas method;
			Linear::Matrix mtx = method.getMatrix();
			std::cout << mtx << '\n';

			Linear::Vector y = method.getSolutions();
			std::cout << "Solution: " << y << '\n';

			using Linear::h; using Linear::u;
			std::cout << "ih \t\t yi \t\t u(ih) \t\t |yi-u(ih)|\n";
			for(int i=0; i<Linear::n; i++)
				std::cout<<i*h<<"\t\t"<<y[i]<<"\t\t"<<u(i*h)<<"\t\t"<<fabs(y[i]-u(i*h))<<'\n';

			std::cout << "******Thomas test end************\n\n";
		}

		static void testSeidel()
		{
			std::cout << "******Seidel test start**********\n";

			Linear::ConcreteIterative::Seidel method;
			Linear::Matrix mtx = method.getMatrix();
			std::cout << mtx << '\n';

			Linear::Vector y = method.getSolutions();
			std::cout << "Solution: " << y << '\n';

			using Linear::h; using Linear::u;
			std::cout << "ih\t\tyi\t\tu(ih)\t\t|yi-u(ih)|\n";
			for (int i = 0; i < Linear::n; i++)
				std::cout << i * h << "\t\t" << y[i] << "\t\t" << u(i * h) << "\t\t" << fabs(y[i] - u(i * h)) << '\n';

			std::cout << "******Seidel test end************\n\n";
		}

		static void testRelaxation()
		{
			std::cout << "******Relaxation test start******\n";

			Linear::ConcreteIterative::Relaxation method;
			Linear::Matrix mtx = method.getMatrix();
			std::cout << mtx << '\n';

			Linear::Vector y = method.getSolutions();
			std::cout << "Solution: " << y << '\n';

			using Linear::h; using Linear::u;
			std::cout << "ih\t\tyi\t\tu(ih)\t\t|yi-u(ih)|\n";
			for (int i = 0; i < Linear::n; i++)
				std::cout << i * h << "\t\t" << y[i] << "\t\t" << u(i * h) << "\t\t" << fabs(y[i] - u(i * h)) << '\n';

			std::cout << "******Relaxation test end********\n\n";
		}

		static void testJacobi()
		{
			std::cout << "******Jacobi test start**********\n";

			Linear::ConcreteIterative::Jacobi method;
			Linear::Matrix mtx = method.getMatrix();
			std::cout << mtx << '\n';

			Linear::Vector y = method.getSolutions();
			std::cout << "Solution: " << y << '\n';

			using Linear::h; using Linear::u;
			std::cout << "ih\t\tyi\t\tu(ih)\t\t|yi-u(ih)|\n";
			for (int i = 0; i < Linear::n; i++)
				std::cout << i * h << "\t\t" << y[i] << "\t\t" << u(i * h) << "\t\t" << fabs(y[i] - u(i * h)) << '\n';

			std::cout << "******Jacobi test end************\n\n";
		}
	};
} // UnitTests
