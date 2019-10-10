#include "pch.h"
#include "CppUnitTest.h"
#include "../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	TEST_CLASS(StrStrTest)
	{
	public:

		TEST_METHOD(Search_For_A_Word_That_Is_In_The_Middle_Of_A_Sentence)
		{
			char sentence[] = "This is a simple string";
			char word[] = "simple";

			char* result = mystrstr(sentence, word);
			
			Assert::AreEqual(&sentence[10], result);
		}

		TEST_METHOD(Search_For_A_Word_That_Is_In_The_Beginning_Of_A_Sentence)
		{
			char sentence[] = "This is a simple string";
			char word[] = "This";

			char* result = mystrstr(sentence, word);

			Assert::AreEqual(&sentence[0], result);
		}

		TEST_METHOD(Search_For_A_Word_That_Is_In_The_End_Of_A_Sentence)
		{
			char sentence[] = "This is a simple string";
			char word[] = "string";

			char* result = mystrstr(sentence, word);

			Assert::AreEqual(&sentence[17], result);
		}

		TEST_METHOD(Not_Found)
		{
			char sentence[] = "This is a simple string";
			char word[] = "mpla";

			char* result = mystrstr(sentence, word);

			Assert::AreEqual(nullptr, result);
		}
	};
}