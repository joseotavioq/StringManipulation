#include "CppUnitTest.h"
#include "../../StringManipulation/Exercises.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	namespace Exercises
	{
		TEST_CLASS(GetWrittenAmountTest)
		{
		public:

			TEST_METHOD(Amount_Of_10)
			{
				char* result = GetWrittenAmount(10);

				Assert::AreEqual("TEN", result);
			}

			/*TEST_METHOD(Amount_Of_1435_46)
			{
				char* result = GetWrittenAmount(1435.46);

				Assert::AreEqual("ONE THOUSAND FOUR HUNDRED THIRTY FIVE AND FOURTY SIX", result);
			}*/

			TEST_METHOD(Amount_Of_100)
			{
				char* result = GetWrittenAmount(100);

				Assert::AreEqual("ONE HUNDRED", result);
			}

			TEST_METHOD(Amount_Of_1000)
			{
				char* result = GetWrittenAmount(1000);

				Assert::AreEqual("ONE THOUSAND", result);
			}

			TEST_METHOD(Amount_Of_10_DECIMAL)
			{
				char* result = GetWrittenAmount(.10);

				Assert::AreEqual("TEN", result);
			}

			/*TEST_METHOD(Amount_Of_11_DECIMAL)
			{
				char* result = GetWrittenAmount(.11);

				Assert::AreEqual("ELEVEN", result);
			}*/

			TEST_METHOD(Amount_Of_21_DECIMAL)
			{
				char* result = GetWrittenAmount(.21);

				Assert::AreEqual("TWEENTY ONE", result);
			}
		};
	}
}