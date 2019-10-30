#include "CppUnitTest.h"
#include "../../StringManipulation/arrays.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	namespace Arrays
	{
		TEST_CLASS(CompressArrayTest)
		{
		public:

			TEST_METHOD(Compress_Array_With_Eight_Elements_In_Five_Elements)
			{
				int A[] = { 1, 1, 2, 2, 3, 3, 4, 5 };
				unsigned int size = 8;

				CompressArray(A, size);

				for (size_t i = 0; i < size; i++)
				{
					int expected = i + 1;
					Assert::AreEqual(expected, A[i]);
				}
			}
		};
	}
}