#include "CppUnitTest.h"
#include "../../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	TEST_CLASS(StrNCpyTest)
	{
	public:

		TEST_METHOD(Basic_Test)
		{
			char str[] = "abc def ghi jkl mno";
			char str1[21];

			mystrncpy(str1, str, sizeof(str1));

			Assert::AreEqual("abc def ghi jkl mno", str1);
			Assert::AreEqual('0', str1[20]);
		}

		TEST_METHOD(Partial_Copy)
		{
			char str[] = "abc def ghi jkl mno";
			char str1[20];

			mystrncpy(str1, str, 7);
			str1[7] = '\0';

			Assert::AreEqual("abc def", str1);
		}
	};
}