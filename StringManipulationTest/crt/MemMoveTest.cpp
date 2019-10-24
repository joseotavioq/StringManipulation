#include "CppUnitTest.h"
#include "../../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	TEST_CLASS(MemMoveTest)
	{
	public:

		TEST_METHOD(Same_Array_With_Src_Greater_Than_Dst)
		{
			char str[] = "abc def ghi jkl mno";

			mymemmove(str + 4, str + 8, 11);

			Assert::AreEqual("abc def def ghi jkl", str);
		}

		TEST_METHOD(Same_Array_With_Dst_Greater_Than_Src)
		{
			char str[] = "abc def ghi jkl mno";

			mymemmove(str + 8, str + 7, 3);

			Assert::AreEqual("abc defghii jkl mno", str);
		}

		TEST_METHOD(With_Two_Array_Of_Char)
		{
			char str1[] = "Tests";
			char str2[] = "ABCD";

			mymemmove(str2, str1, 5);

			Assert::AreEqual("ABCD", str1);
		}

		TEST_METHOD(Without_Memory_Allocation_Same_Array_With_Src_Greater_Than_Dst)
		{
			char str[] = "abc def ghi jkl mno";

			mymemmove_without_memory_allocation(str + 4, str + 8, 11);

			Assert::AreEqual("abc def def ghi jkl", str);
		}

		TEST_METHOD(Without_Memory_Allocation_Same_Array_With_Dst_Greater_Than_Src)
		{
			char str[] = "abc def ghi jkl mno";

			mymemmove_without_memory_allocation(str + 8, str + 7, 3);

			Assert::AreEqual("abc defghii jkl mno", str);
		}

		TEST_METHOD(Without_Memory_Allocation_With_Two_Array_Of_Char)
		{
			char str1[] = "Tests";
			char str2[] = "ABCD";

			mymemmove_without_memory_allocation(str2, str1, 5);

			Assert::AreEqual("ABCD", str1);
		}
	};
}