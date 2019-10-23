#include "pch.h"
#include "CppUnitTest.h"
#include "../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	TEST_CLASS(ItoStrBinTest)
	{
	public:

		TEST_METHOD(Convert_161_To_Bin_11000000111001)
		{
			unsigned int value = 12345;
			char str[15];

			itostrbin(value, str);

			Assert::AreEqual("11000000111001", str);
		}

		TEST_METHOD(Convert_10_To_Bin_1010)
		{
			unsigned int value = 10;
			char str[5];

			itostrbin(value, str);

			Assert::AreEqual("1010", str);
		}

		TEST_METHOD(Convert_10101_To_Bin_10011101110101)
		{
			unsigned int value = 10101;
			char str[15];

			itostrbin(value, str);

			Assert::AreEqual("10011101110101", str);
		}
	};
}