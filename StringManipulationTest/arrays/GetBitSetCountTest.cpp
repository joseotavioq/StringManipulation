#include "CppUnitTest.h"
#include "../../StringManipulation/arrays.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	namespace Arrays
	{
		TEST_CLASS(GetBitSetCountTest)
		{
		public:

			TEST_METHOD(Value_65000_Returns_11)
			{
				int result = GetBitSetCount(65000);

				Assert::AreEqual(11, result);
			}
		};
	}
}