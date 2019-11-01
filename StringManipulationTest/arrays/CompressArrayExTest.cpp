#include "CppUnitTest.h"
#include "../../StringManipulation/arrays.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	namespace Arrays
	{
		TEST_CLASS(CompressArrayExTest)
		{
		public:

			TEST_METHOD(Compress_Array_With_Eight_Elements_In_Five_Elements)
			{
				int A[] = { 1, 1, 2, 2, 3, 3, 4, 5 };
				unsigned int size = 8;

				CompressArrayEx(A, size);

				Assert::AreEqual(5, (int)size);
				for (size_t i = 0; i < size; i++)
				{
					int expected = i + 1;
					Assert::AreEqual(expected, A[i]);
				}
			}

			TEST_METHOD(Compress_Array_With_Ten_Elements_In_Five_Elements)
			{
				int A[] = { 1, 2, 3, 2, 3, 4, 5, 4, 2, 1 };
				unsigned int size = 10;

				CompressArrayEx(A, size);

				Assert::AreEqual(5, (int)size);
				for (size_t i = 0; i < size; i++)
				{
					int expected = i + 1;
					Assert::AreEqual(expected, A[i]);
				}
			}
		};
	}
}