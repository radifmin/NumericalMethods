#include "stdafx.h"

#ifdef DEBUG_LIB
#include "NumMethods/TestMethods/testLinearEquation.h"
#endif // DEBUG_LIB


int main()
{
	// Iterative methods tests
	UnitTests::testLinearEquation::testThomas();
	UnitTests::testLinearEquation::testDownRelaxation();
	UnitTests::testLinearEquation::testUpRelaxation();
	UnitTests::testLinearEquation::testJacobi();
	UnitTests::testLinearEquation::testSeidel();
	UnitTests::testLinearEquation::testGradientDescent();
	return 0;
}
