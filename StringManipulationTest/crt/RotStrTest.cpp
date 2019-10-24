#include "CppUnitTest.h"
#include "../../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	TEST_CLASS(RotStrTest)
	{
	public:

		TEST_METHOD(Rotate_Left)
		{
			char str[] = "abcdefg";

			char* result = rotstr(str);

			Assert::AreEqual("bcdefga", result);
		}
	};
}