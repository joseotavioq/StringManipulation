#include "CppUnitTest.h"
#include "../../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	TEST_CLASS(StrNCatTest)
	{
	public:

		TEST_METHOD(Cat_Two_Strings)
		{
			char str1[] = "To be ";
			char str2[] = "or not to be";

			mystrncat(str2, str1, 6);
			
			Assert::AreEqual("To be or not", str2);
		}

		TEST_METHOD(Source_Is_Less_Than_Count)
		{
			char str1[] = "To be ";
			char str2[] = "or not to be";

			mystrncat(str2, str1, 8);

			Assert::AreEqual("To be or not", str2);
		}
	};
}