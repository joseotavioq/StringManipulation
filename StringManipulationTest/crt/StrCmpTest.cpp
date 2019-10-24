#include "CppUnitTest.h"
#include "../../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	namespace CRT
	{
		TEST_CLASS(StrCmpTest)
		{
		public:

			TEST_METHOD(Both_Strings_Are_Equal)
			{
				char str[] = "abc";
				char str1[] = "abc";

				int result = mystrcmp(str, str1);

				Assert::AreEqual(0, result);
			}

			TEST_METHOD(First_String_Is_Less_Than_The_Other)
			{
				char str[] = "abc";
				char str1[] = "acc";

				int result = mystrcmp(str, str1);

				Assert::AreEqual(-1, result);
			}

			TEST_METHOD(First_String_Is_Greater_Than_The_Other)
			{
				char str[] = "abc";
				char str1[] = "aac";

				int result = mystrcmp(str, str1);

				Assert::AreEqual(1, result);
			}

			TEST_METHOD(End_Of_String_Reached)
			{
				char str[] = "abc";
				char str1[] = "abc";

				int result = mystrcmp(str, str1);

				Assert::AreEqual(0, result);
			}

			TEST_METHOD(End_Of_String_Reached_With_Different_Count_Of_Characters)
			{
				char str[] = "abc";
				char str1[] = "ab";

				int result = mystrcmp(str, str1);

				Assert::AreEqual(99, result);
			}

			TEST_METHOD(The_Last_Character_Is_Different)
			{
				char str[] = "abcd";
				char str1[] = "abce";

				int result = mystrcmp(str, str1);

				Assert::AreEqual(-1, result);
			}
		};
	}
}