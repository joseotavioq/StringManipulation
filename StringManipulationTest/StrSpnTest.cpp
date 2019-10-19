#include "pch.h"
#include "CppUnitTest.h"
#include "../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	TEST_CLASS(StrSpnTest)
	{
	public:

		TEST_METHOD(BigO_Of_N_Count_Elements_In_The_First_Parameter_In_Which_Exists_On_The_Other_Parameter)
		{
			char text[] = "129th";
			char cset[] = "1234567890";

			int count = mystrspn_bigO_of_n(text, cset);

			Assert::AreEqual(3, count);
		}

		TEST_METHOD(BigO_Of_N_Count_Elements_In_The_First_Parameter_In_Which_Not_Exists_On_The_Other_Parameter)
		{
			char text[] = "abcth";
			char cset[] = "1234567890";

			int count = mystrspn_bigO_of_n(text, cset);

			Assert::AreEqual(0, count);
		}

		TEST_METHOD(BigO_Of_N_All_Char_From_The_First_Parameter_Exists_On_The_Other_Parameter)
		{
			char text[] = "93876";
			char cset[] = "1234567890";

			int count = mystrspn_bigO_of_n(text, cset);

			Assert::AreEqual(5, count);
		}

		TEST_METHOD(BigO_Of_N_Testing_An_Example_From_Docs)
		{
			char text[] = "cabbage";
			char cset[] = "abc";

			int  count = mystrspn_bigO_of_n(text, cset);

			Assert::AreEqual(5, count);
		}
		TEST_METHOD(BigO_Of_N_M_Count_Elements_In_The_First_Parameter_In_Which_Exists_On_The_Other_Parameter)
		{
			char text[] = "129th";
			char cset[] = "1234567890";

			int count = mystrspn_bigO_of_n_m(text, cset);

			Assert::AreEqual(3, count);
		}

		TEST_METHOD(BigO_Of_N_M_Count_Elements_In_The_First_Parameter_In_Which_Not_Exists_On_The_Other_Parameter)
		{
			char text[] = "abcth";
			char cset[] = "1234567890";

			int count = mystrspn_bigO_of_n_m(text, cset);

			Assert::AreEqual(0, count);
		}

		TEST_METHOD(BigO_Of_N_M_All_Char_From_The_First_Parameter_Exists_On_The_Other_Parameter)
		{
			char text[] = "93876";
			char cset[] = "1234567890";

			int count = mystrspn_bigO_of_n_m(text, cset);

			Assert::AreEqual(5, count);
		}

		TEST_METHOD(BigO_Of_N_M_Testing_An_Example_From_Docs)
		{
			char text[] = "cabbage";
			char cset[] = "abc";

			int  count = mystrspn_bigO_of_n_m(text, cset);

			Assert::AreEqual(5, count);
		}
	};
}