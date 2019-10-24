#include "CppUnitTest.h"
#include "../../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	namespace CRT
	{
		TEST_CLASS(RemCharsTest)
		{
		public:

			TEST_METHOD(Remove_Chars_Contained_In_The_Second_Parameter)
			{
				char str[] = "abcdefg";
				char ctrl[] = "ac";

				char* result = remchars(str, ctrl, 2);

				Assert::AreEqual("bdefg", result);
			}

			TEST_METHOD(Remove_Almost_Every_Char_That_Contained_In_The_Second_Parameter)
			{
				char str[] = "abcdefg";
				char ctrl[] = "acdfg";

				char* result = remchars(str, ctrl, 5);

				Assert::AreEqual("be", result);
			}

			TEST_METHOD(Remove_All_Chars_Contained_In_The_Second_Parameter)
			{
				char str[] = "abcdefg";
				char ctrl[] = "gfedcba";

				char* result = remchars(str, ctrl, 7);

				Assert::AreEqual("", result);
			}
		};
	}
}