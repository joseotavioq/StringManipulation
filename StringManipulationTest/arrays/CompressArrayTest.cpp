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
				unsigned int size = 10;

				CompressArray(A, size);

				Assert::AreEqual(1, A[0]);
				Assert::AreEqual(2, A[1]);
				Assert::AreEqual(3, A[2]);
				Assert::AreEqual(4, A[3]);
				Assert::AreEqual(5, A[4]);
			}
		};
	}
}