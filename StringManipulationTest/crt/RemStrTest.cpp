#include "CppUnitTest.h"
#include "../../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	namespace CRT
	{
		TEST_CLASS(RemStrTest)
		{
		public:

			TEST_METHOD(Remove_The_End_Of_A_String)
			{
				char sentence[] = "The cat and the dog";

				char* result = remstr(sentence, 7, 12);

				Assert::AreEqual("The cat", result);
			}

			TEST_METHOD(Remove_The_Beggining_Of_A_String)
			{
				char sentence[] = "The cat and the dog";

				char* result = remstr(sentence, 0, 12);

				Assert::AreEqual("the dog", result);
			}

			TEST_METHOD(Remove_The_Middle_Of_A_String)
			{
				char sentence[] = "The cat and the dog";

				char* result = remstr(sentence, 11, 4);

				Assert::AreEqual("The cat and dog", result);
			}
		};
	}
}