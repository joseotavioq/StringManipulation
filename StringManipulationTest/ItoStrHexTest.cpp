#include "pch.h"
#include "CppUnitTest.h"
#include "../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	TEST_CLASS(ItoStrHexTest)
	{
	public:

		TEST_METHOD(Convert_161_To_Hex_A1)
		{
			unsigned int value = 161;
			char str[3];

			itostrhex(value, str);

			Assert::AreEqual("A1", str);
		}

		TEST_METHOD(Convert_39554_To_Hex_9A82)
		{
			unsigned int value = 39554;
			char str[5];

			itostrhex(value, str);

			Assert::AreEqual("9A82", str);
		}

		TEST_METHOD(Convert_2856_To_Hex_B28)
		{
			unsigned int value = 2856;
			char str[4];

			itostrhex(value, str);

			Assert::AreEqual("B28", str);
		}

		TEST_METHOD(Convert_37_To_Hex_25)
		{
			unsigned int value = 37;
			char str[3];

			itostrhex(value, str);

			Assert::AreEqual("25", str);
		}
	};
}