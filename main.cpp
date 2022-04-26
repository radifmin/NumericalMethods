#include "stdafx.h"

#ifdef DEBUG_LIB
#include "NumMethods/TestMethods/testLinearEquation.h"
#endif // DEBUG_LIB


int main()
{
	//// Iterative methods tests
	//UnitTests::testLinearEquation::testThomas();
	//UnitTests::testLinearEquation::testUpRelaxation();
	//UnitTests::testLinearEquation::testDownRelaxation();
	//UnitTests::testLinearEquation::testJacobi();
	UnitTests::testLinearEquation::testSeidel();
	UnitTests::testLinearEquation::testGradientDescent();
	system("pause");
	return 0;
}
