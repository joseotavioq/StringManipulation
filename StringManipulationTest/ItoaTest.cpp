#include "pch.h"
#include "CppUnitTest.h"
#include "../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	TEST_CLASS(ItoaTest)
	{
	public:

		TEST_METHOD(Convert_Simple_Number)
		{
			char text[4];

			myitoa(129, text);

			Assert::AreEqual("129", text);
		}

		TEST_METHOD(Convert_Negative_Number)
		{
			char text[5];

			myitoa(-129, text);

			Assert::AreEqual("-129", text);
		}
	};
}