#include "pch.h"
#include "CppUnitTest.h"
#include "../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	TEST_CLASS(StrNCatTest)
	{
	public:

		TEST_METHOD(Cat_Two_Strings)
		{
			char src[] = "To be ";
			char dst[] = "or not to be";

			mystrncat(dst, src, 6);

			Assert::AreEqual("To be or not", dst);
		}

		TEST_METHOD(Source_Is_Less_Than_Count)
		{
			char src[] = "To be ";
			char dst[] = "or not to be";

			mystrncat(dst, src, 8);

			Assert::AreEqual("To be or not", dst);
		}
	};
}