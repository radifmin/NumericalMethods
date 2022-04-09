#pragma once
#include "stdafx.h"

namespace Linear
{
	class Vector
	{
		std::array<double, n> v;
	public:
		double& operator[](int i) { return v[i]; }
		const double& operator[](int i) const { return v[i]; }
		void printVert() const {
			for (int i = 0; i < n; i++)
				std::cout << v[i] << '\n';
		}
		friend std::ostream& operator<<(std::ostream& os, const Linear::Vector& v)
		{
			for (int i = 0; i < Linear::n; i++)
				os << v[i] << ' ';
			//os << '\n';
			return os;
		}
	};
	class Matrix
	{
		std::array<Vector, n> mtx;
	public:
		Matrix() { std::cout << "Matrix with dimension " << n << " has instantiated.\n"; }
		Vector& operator[](int i) { return mtx[i]; }
		const Vector& operator[](int i) const { return mtx[i]; }
		friend std::ostream& operator<<(std::ostream& os, const Linear::Matrix& mtx)
		{
			os << "Matrix<" << n << ">:\n";
			for (int i = 0; i < Linear::n; i++)
				os << mtx[i];
			return os;
		}
	};
} // Linear
