#include "pch.h"
#include "CppUnitTest.h"
#include "../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	TEST_CLASS(StrCpyTest)
	{
	public:

		TEST_METHOD(Basic_Test)
		{
			char str[] = "abc def ghi jkl mno";
			char str1[20];

			mystrcpy(str1, str);

			Assert::AreEqual("abc def ghi jkl mno", str1);
		}

		TEST_METHOD(Partial_Copy)
		{
			char str[] = "abc def ghi jkl mno";
			char str1[20];

			mystrcpy(str1, str);
			str1[7] = '\0';

			Assert::AreEqual("abc def", str1);
		}
	};
}