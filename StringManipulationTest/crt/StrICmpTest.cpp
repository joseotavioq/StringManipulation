#include "CppUnitTest.h"
#include "../../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	TEST_CLASS(StrICmpTest)
	{
	public:

		TEST_METHOD(Both_Strings_Are_Equal)
		{
			char str[] = "ABC";
			char str1[] = "abc";

			int result = mystricmp(str, str1);

			Assert::AreEqual(0, result);
		}

		TEST_METHOD(Both_Strings_In_Lowercase_Are_Equal)
		{
			char str[] = "abc";
			char str1[] = "abc";

			int result = mystricmp(str, str1);

			Assert::AreEqual(0, result);
		}

		TEST_METHOD(First_String_Is_Less_Than_The_Other)
		{
			char str[] = "abc";
			char str1[] = "ACC";

			int result = mystricmp(str, str1);

			Assert::AreEqual(-1, result);
		}

		TEST_METHOD(First_String_Is_Greater_Than_The_Other)
		{
			char str[] = "ABC";
			char str1[] = "aac";

			int result = mystricmp(str, str1);

			Assert::AreEqual(1, result);
		}

		TEST_METHOD(End_Of_String_Reached)
		{
			char str[] = "abc";
			char str1[] = "ABC";

			int result = mystricmp(str, str1);

			Assert::AreEqual(0, result);
		}

		TEST_METHOD(End_Of_String_Reached_With_Different_Count_Of_Characters)
		{
			char str[] = "abc";
			char str1[] = "AB";

			int result = mystricmp(str, str1);

			Assert::AreEqual(99, result);
		}

		TEST_METHOD(The_Last_Character_Is_Different)
		{
			char str[] = "ABCD";
			char str1[] = "abce";

			int result = mystricmp(str, str1);

			Assert::AreEqual(-1, result);
		}
	};
}