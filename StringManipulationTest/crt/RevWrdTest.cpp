#include "CppUnitTest.h"
#include "../../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	namespace CRT
	{
		TEST_CLASS(RevWrdTest)
		{
		public:

			TEST_METHOD(Revert_Words_With_Count_Equals_To_Even)
			{
				char sentence[] = "The cat and the dog";

				char* result = revwrd(sentence);

				Assert::AreEqual("dog the and cat The", result);
			}

			TEST_METHOD(Revert_Words_With_Count_Equals_To_Odd)
			{
				char sentence[] = "This is simple string";

				char* result = revwrd(sentence);

				Assert::AreEqual("string simple is This", result);
			}

			TEST_METHOD(Only_One_Word)
			{
				char sentence[] = "Hey";

				char* result = revwrd(sentence);

				Assert::AreEqual("Hey", result);
			}
		};
	}
}