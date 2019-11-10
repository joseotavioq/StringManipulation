#include "CppUnitTest.h"
#include "../../StringManipulation/Exercises.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	namespace Exercises
	{
		TEST_CLASS(PrintSievePrimeNumbersTest)
		{
		public:

			TEST_METHOD(Prime_Numbers_From_1_To_10_Is_4)
			{
				int result = PrintSievePrimeNumbers(10);

				Assert::AreEqual(4, result);
			}

			TEST_METHOD(Prime_Numbers_From_1_To_200_Is_46)
			{
				int result = PrintSievePrimeNumbers(200);

				Assert::AreEqual(46, result);
			}
		};
	}
}