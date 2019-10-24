#include "CppUnitTest.h"
#include "../../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	namespace CRT
	{
		TEST_CLASS(RotCharsTest)
		{
		public:

			TEST_METHOD(Rotate_Left)
			{
				char str[] = "abcdefg";

				char* result = rotchars(str, 7);

				Assert::AreEqual("bcdefga", result);
			}
		};
	}
}