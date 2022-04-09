#include "stdafx.h"

#ifdef DEBUG_LIB
#include "NumMethods/TestMethods/testLinearEquation.h"
#endif // DEBUG_LIB


int main()
{

	UnitTests::testLinearEquation::testThomas();
	UnitTests::testLinearEquation::testSeidel();
	UnitTests::testLinearEquation::testRelaxation();
	UnitTests::testLinearEquation::testJacobi();

	return 0;
}
