#pragma once
namespace Linear
{
	const double alpha = 3.0;
	const double betta = 3.0;
	const double gamma = 5.0;
	const int n = 20;
	const double h = 1.0 / double(n);
	const double EPS = h * h * h*h;

	double p(double x)
	{
		return 1 + std::pow(x, gamma);
	}
	double p_(double x)
	{
		return gamma
			*(gamma==1?1:std::pow(x, gamma - 1));
	}
	double q(double x)
	{
		return x + 1;
	}
	double u(double x)
	{
		return std::pow(x, alpha)
			*std::pow(1 - x, betta);
	}
	double u_(double x)
	{
		return alpha * betta
			*(alpha==1?1:std::pow(x, alpha - 1))
			*(betta==1?1:std::pow(1 - x, betta - 1))
		    -betta * std::pow(x, alpha)
			*(betta==1?1:std::pow(1 - x, betta - 1));
	}
	double u__(double x)
	{
		return alpha
			*(alpha - 1)
			*(alpha==2?1:std::pow(x, alpha - 2))
			*std::pow(1 - x, betta)
			-2 * alpha * betta
			*(alpha==1?1:std::pow(x, alpha - 1))
			*(betta==1?1:std::pow(1 - x, betta - 1))
			+betta * (betta - 1) * std::pow(x, alpha)
			*(betta==2?1:std::pow(1 - x, betta - 2));
	}
	double f(double x)
	{
		return -(p_(x) * u_(x) + p(x) * u__(x)) + q(x) * u(x);
	}
	double f(int i)
	{
		return f(double(i) * h);
	}
	double a(int i)
	{
		return p(double(i) * h);
	}
	double g(int i)
	{
		return q(double(i) * h);
	}
} // Linear
