#include "pch.h"
#include "CppUnitTest.h"
#include "../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	TEST_CLASS(StrSpnTest)
	{
	public:

		TEST_METHOD(Count_Elements_In_The_First_Parameter_In_Which_Exists_On_The_Other_Parameter)
		{
			char text[] = "129th";
			char cset[] = "1234567890";

			int count = mystrspn(text, cset);

			Assert::AreEqual(3, count);
		}

		TEST_METHOD(Count_Elements_In_The_First_Parameter_In_Which_Not_Exists_On_The_Other_Parameter)
		{
			char text[] = "abcth";
			char cset[] = "1234567890";

			int count = mystrspn(text, cset);

			Assert::AreEqual(0, count);
		}

		TEST_METHOD(All_Char_From_The_First_Parameter__Exists_On_The_Other_Parameter)
		{
			char text[] = "93876";
			char cset[] = "1234567890";

			int count = mystrspn(text, cset);

			Assert::AreEqual(5, count);
		}
	};
}