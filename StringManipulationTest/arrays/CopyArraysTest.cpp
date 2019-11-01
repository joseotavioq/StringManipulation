#include "CppUnitTest.h"
#include "../../StringManipulation/arrays.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	namespace Arrays
	{
		TEST_CLASS(CopyArraysTest)
		{
		public:

			TEST_METHOD(Copy_A_And_B_Into_C)
			{
				int A[] = { 1, 1, 2, 2, 3, 3, 4, 5 };
				unsigned int sizeA = 8;
				int B[] = { 1, 2, 2, 3, 4, 4, 5, 5 };
				unsigned int sizeB = 8;
				int* C = new int[sizeA + sizeB];

				CopyArrays(A, sizeA, B, sizeB, C);

				for (size_t i = 1; i <= 10; i++)
				{
					if (i <= 5)
						Assert::AreEqual((int)i, C[i - 1]);
					else
						Assert::AreEqual((int)(i - 5), C[i - 1]);
				}
			}
		};
	}
}