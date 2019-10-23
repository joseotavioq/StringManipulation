#include "pch.h"
#include "CppUnitTest.h"
#include "../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	TEST_CLASS(RotNStrTest)
	{
	public:

		TEST_METHOD(Rotate_7_Chars_Left)
		{
			char str[] = "abcdefg";

			char* result = rotnstr(str, 7);

			Assert::AreEqual("abcdefg", result);
		}

		TEST_METHOD(Rotate_3_Chars_Left)
		{
			char str[] = "abcdefg";

			char* result = rotnstr(str, 3);

			Assert::AreEqual("defgabc", result);
		}
	};
}