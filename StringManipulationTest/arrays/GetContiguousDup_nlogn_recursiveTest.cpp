#include "CppUnitTest.h"
#include "../../StringManipulation/arrays.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	namespace Arrays
	{
		TEST_CLASS(GetContiguousDup_nlogn_recursiveTest)
		{
		public:

			TEST_METHOD(Return_The_Duplicate_At_Index_3)
			{
				int A[] = { 1, 3, 4, 4, 2 };
				int size = 5;

				int duplicateIndex = GetContiguousDup_nlogn_recursive(A, size, 0);

				Assert::AreEqual(3, duplicateIndex);
			}

			TEST_METHOD(Return_The_Duplicate_At_Index_4)
			{
				int A[] = { 2, 3, 1, 4, 4 };
				int size = 5;

				int duplicateIndex = GetContiguousDup_nlogn_recursive(A, size, 0);

				Assert::AreEqual(4, duplicateIndex);
			}

			TEST_METHOD(Return_The_Duplicate_At_Index_2)
			{
				int A[] = { 2, 1, 1, 4 };
				int size = 4;

				int duplicateIndex = GetContiguousDup_nlogn_recursive(A, size, 0);

				Assert::AreEqual(2, duplicateIndex);
			}

			TEST_METHOD(No_Duplicate_In_Array_Returns_Minus_One)
			{
				int A[] = { 1, 2, 3, 4, 5 };
				int size = 5;

				int duplicateIndex = GetContiguousDup_nlogn_recursive(A, size, 0);

				Assert::AreEqual(-1, duplicateIndex);
			}
		};
	}
}