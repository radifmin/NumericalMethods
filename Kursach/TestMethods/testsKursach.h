#pragma once
#include "stdafx.h"

namespace UnitTests
{
	class testKursach
	{
	public:
		static void testExercise()
		{
			Tumor t{};
			t.Solute();
			t.get_Solutions();
		}
	};
}
