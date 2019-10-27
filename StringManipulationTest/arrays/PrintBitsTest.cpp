#include "CppUnitTest.h"
#include "../../StringManipulation/arrays.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	namespace Arrays
	{
		TEST_CLASS(PrintBitsTest)
		{
		public:

			TEST_METHOD(Print_The_Bits_From_65000)
			{
				char* result = PrintBits(65000);

				Assert::AreEqual("1111 1101 1110 1000", result);
			}
		};
	}
}