#include "pch.h"
#include "CppUnitTest.h"
#include "../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	TEST_CLASS(InsertStrTest)
	{
	public:

		TEST_METHOD(Basic_Test)
		{
			char str[] = "abc def ghi jkl mno";

			insertstr(str, str + 4, 8);

			Assert::AreEqual("abc def def ghi jkl", str);
		}

		TEST_METHOD(With_Two_Array_Of_Chars)
		{
			char str1[] = "Tests";
			char str2[] = "ABCD";

			insertstr(str1, str2, 0);

			Assert::AreEqual("ABCDs", str1);
		}
	};
}