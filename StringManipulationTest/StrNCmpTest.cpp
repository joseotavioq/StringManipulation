#include "pch.h"
#include "CppUnitTest.h"
#include "../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	TEST_CLASS(StrNCmpTest)
	{
	public:

		TEST_METHOD(Both_Strings_Are_Equal)
		{
			char str[] = "abc";
			char str1[] = "abc";

			int result = mystrncmp(str, str1, 3);

			Assert::AreEqual(0, result);
		}

		TEST_METHOD(First_String_Is_Less_Than_The_Other)
		{
			char str[] = "abc";
			char str1[] = "acc";

			int result = mystrncmp(str, str1, 3);

			Assert::AreEqual(-1, result);
		}

		TEST_METHOD(First_String_Is_Greater_Than_The_Other)
		{
			char str[] = "abc";
			char str1[] = "aac";

			int result = mystrncmp(str, str1, 3);

			Assert::AreEqual(1, result);
		}

		TEST_METHOD(End_Of_String_Reached)
		{
			char str[] = "abc";
			char str1[] = "abc";

			int result = mystrncmp(str, str1, 4);

			Assert::AreEqual(0, result);
		}

		TEST_METHOD(The_Last_Character_Is_Different)
		{
			char str[] = "abcd";
			char str1[] = "abce";

			int result = mystrncmp(str, str1, 4);

			Assert::AreEqual(-1, result);
		}
	};
}