#include "pch.h"
#include "CppUnitTest.h"
#include "../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	TEST_CLASS(MemMoveTest)
	{
	public:

		TEST_METHOD(Basic_Test)
		{
			char str[] = "abc def ghi jkl mno";

			mymemmove(str + 4, str + 8, 11);

			Assert::AreEqual("abc def def ghi jkl", str);
		}

		TEST_METHOD(With_Two_Array_Of_Char)
		{
			char str1[] = "Tests";
			char str2[] = "ABCD";

			mymemmove(str2, str1, 5);

			Assert::AreEqual("ABCD", str1);
		}
	};
}