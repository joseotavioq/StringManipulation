#include "CppUnitTest.h"
#include "../../StringManipulation/arrays.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	namespace Arrays
	{
		TEST_CLASS(VectorInfoTest)
		{
		public:

			TEST_METHOD(Call_Method_GetMaxSumVector_n2)
			{
				int A[] = { 1, -2, 3, 4 };

				VectorInfo* result = GetMaxSumVector_n2(A, 4);

				Assert::AreEqual(2, result->StartIndex);
				Assert::AreEqual(1, result->Count);
				Assert::AreEqual(7, result->Sum);
			}
		};
	}
}