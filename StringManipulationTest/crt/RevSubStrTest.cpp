#include "CppUnitTest.h"
#include "../../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	TEST_CLASS(RevSubStrTest)
	{
	public:

		TEST_METHOD(Invert_At_The_Beggining_Of_The_Content)
		{
			char content[] = "abcefg";

			char* result = revsubstr(content, 0, 4);

			Assert::AreEqual("ecbafg", result);
		}

		TEST_METHOD(Invert_In_The_Middle_Of_The_Content)
		{
			char content[] = "abcefg";

			char* result = revsubstr(content, 1, 3);

			Assert::AreEqual("aecbfg", result);
		}

		TEST_METHOD(Invert_In_The_End_Of_The_Content)
		{
			char content[] = "abcefg";

			char* result = revsubstr(content, 4, 2);

			Assert::AreEqual("abcegf", result);
		}

		TEST_METHOD(Invert_The_Entire_Content)
		{
			char content[] = "abcefg";

			char* result = revsubstr(content, 0, 6);

			Assert::AreEqual("gfecba", result);
		}
	};
}