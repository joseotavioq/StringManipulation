#include "pch.h"
#include "CppUnitTest.h"
#include "../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	TEST_CLASS(AtoiTest)
	{
	public:

		TEST_METHOD(Convert_Simple_Number)
		{
			char text[] = "129";

			int number = myatoi(text);

			Assert::AreEqual(129, number);
		}

		TEST_METHOD(Convert_Negative_Number)
		{
			char text[] = "-129";

			int number = myatoi(text);

			Assert::AreEqual(-129, number);
		}

		TEST_METHOD(Convert_Number_Inside_Other_Chars)
		{
			char text[] = "  129   ";

			int number = myatoi(text);

			Assert::AreEqual(129, number);
		}
	};
}