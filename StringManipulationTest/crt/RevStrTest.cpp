#include "CppUnitTest.h"
#include "../../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	TEST_CLASS(RevStrTest)
	{
	public:

		TEST_METHOD(Invert_Sentence_With_Count_Equals_To_Odd)
		{
			char sentence[] = "This is a simple string";

			char* result = revstr(sentence);

			Assert::AreEqual("gnirts elpmis a si sihT", result);
		}

		TEST_METHOD(Invert_Sentence_With_Count_Equals_To_Even)
		{
			char sentence[] = "This is simple";

			char* result = revstr(sentence);

			Assert::AreEqual("elpmis si sihT", result);
		}
	};
}