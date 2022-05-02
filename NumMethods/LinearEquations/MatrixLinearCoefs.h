#pragma once
#include "stdafx.h"

namespace Linear
{
	class Vector
	{
		std::array<double, n> v;
	public:
		Vector() { for (int i = 0; i < n; i++) v[i] = 0.0; }
		double& operator[](int i) { return v[i]; }
		const double& operator[](int i) const { return v[i]; }
		void printVert() const {
			for (int i = 0; i < n; i++)
				std::cout << v[i] << '\n';
		}
		friend std::ostream& operator<<(std::ostream& os, const Linear::Vector& v)
		{
			for (int i = 0; i < n; i++)
				os << v[i] << ' ';
			//os << '\n';
			return os;
		}
	};
	class Matrix
	{
		std::array<Vector, n> mtx;
	public:
		//Matrix() { std::cout << "Matrix with dimension " << n << " has instantiated.\n"; }
		Matrix() = default;
		Vector& operator[](int i) { return mtx[i]; }
		const Vector& operator[](int i) const { return mtx[i]; }
		friend std::ostream& operator<<(std::ostream& os, const Linear::Matrix& mtx)
		{
			os << "Matrix<" << n << ">:\n";
			for (int i = 0; i < n-1; i++)
				os << mtx[i]<<'\n';
			os << mtx[n-1];
			return os;
		}
	};
	double operator*(const Vector& v1, const Vector& v2)
	{
		double res = 0.0;
		for (int i = 0; i < n; i++)
			res += v1[i] * v2[i];
		return res;
	}
	Vector operator*(const Matrix& m, const Vector& v)
	{
		Vector res;
		for (int i = 0; i < n; i++)
		{
			res[i] = m[i] * v;
		}
		return res;
	}
	Vector abs(Vector v)
	{
		for (int i = 0; i < n; i++)
			v[i] = std::abs(v[i]);
		return v;
	}
	bool operator>(const Vector& v, double val)
	{
		for (int i = 1; i < n-1; i++)
			if (v[i] < val) return false;
		return true;
	}
} // Linear
