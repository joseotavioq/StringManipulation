#include "CppUnitTest.h"
#include "../../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	TEST_CLASS(MemSetTest)
	{
	public:

		TEST_METHOD(Basic_Test)
		{
			char str[] = "abc def ghi jkl mno";

			mymemset(str, 'x', 3);

			Assert::AreEqual("xxx def ghi jkl mno", str);
		}

		TEST_METHOD(Changing_In_The_Middle)
		{
			char str[] = "abc def ghi jkl mno";

			mymemset(str + 8, 'x', 4);

			Assert::AreEqual("abc def xxxxjkl mno", str);
		}
	};
}