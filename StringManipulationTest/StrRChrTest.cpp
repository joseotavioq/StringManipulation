#include "pch.h"
#include "CppUnitTest.h"
#include "../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	TEST_CLASS(StrRChrTest)
	{
	public:

		TEST_METHOD(Search_For_The_Last_Char_s_In_A_Sentence)
		{
			char sentence[] = "This is a simple string";
			char character = 's';

			char* result = mystrrchr(sentence, character);

			Assert::AreEqual(&sentence[17], result);
		}

		TEST_METHOD(Search_For_The_Null_Termination_Char_In_A_Sentence)
		{
			char sentence[] = "This is a simple string";
			char character = '\0';

			char* result = mystrrchr(sentence, character);

			Assert::AreEqual(&sentence[23], result);
		}

		TEST_METHOD(Search_For_The_Null_Termination_Char_In_The_Middle_Of_A_Sentence)
		{
			char sentence[] = "This is a \0simple string";
			char character = '\0';

			char* result = mystrrchr(sentence, character);

			Assert::AreEqual(&sentence[10], result);
		}

		TEST_METHOD(Not_Found)
		{
			char sentence[] = "This is a simple string";
			char character = 'k';

			char* result = mystrrchr(sentence, character);

			Assert::AreEqual(nullptr, result);
		}
	};
}