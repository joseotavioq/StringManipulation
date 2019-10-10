#include "pch.h"
#include "CppUnitTest.h"
#include "../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	TEST_CLASS(StrChrTest)
	{
	public:

		TEST_METHOD(Search_For_The_First_Char_s_In_A_Sentence)
		{
			char sentence[] = "This is a simple string";
			char character = 's';

			char* result = mystrchr(sentence, character);

			Assert::AreEqual(&sentence[3], result);
		}

		TEST_METHOD(Search_For_The_Null_Termination_Char_In_A_Sentence)
		{
			char sentence[] = "This is a simple string";
			char character = '\0';

			char* result = mystrchr(sentence, character);

			Assert::AreEqual(&sentence[23], result);
		}

		TEST_METHOD(Not_Found)
		{
			char sentence[] = "This is a simple string";
			char character = 'k';

			char* result = mystrchr(sentence, character);

			Assert::AreEqual(nullptr, result);
		}
	};
}