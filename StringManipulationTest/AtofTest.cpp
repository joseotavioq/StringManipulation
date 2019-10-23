#include "pch.h"
#include "CppUnitTest.h"
#include "../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	TEST_CLASS(AtofTest)
	{
	public:

		TEST_METHOD(Convert_Simple_Number)
		{
			char text[] = "129.09";

			float number = myatof(text);

			Assert::AreEqual(129.09f, number);
		}

		TEST_METHOD(Convert_Negative_Number)
		{
			char text[] = "-129.8";

			float number = myatof(text);

			Assert::AreEqual(-129.8f, number);
		}

		TEST_METHOD(Convert_Number_Inside_Other_Chars)
		{
			char text[] = "  129.73   ";

			float number = myatof(text);

			Assert::AreEqual(129.73f, number);
		}
	};
}