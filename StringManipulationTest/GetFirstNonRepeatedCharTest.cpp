#include "pch.h"
#include "CppUnitTest.h"
#include "../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	TEST_CLASS(GetFirstNonRepeatedCharTest)
	{
	public:

		TEST_METHOD(Get_o_from_str_total)
		{
			char str[] = "total";

			char result = GetFirstNonRepeatedChar(str);

			Assert::AreEqual('o', result);
		}

		TEST_METHOD(Get_a_from_str_abcdef)
		{
			char str[] = "abcdef";

			char result = GetFirstNonRepeatedChar(str);

			Assert::AreEqual('a', result);
		}

		TEST_METHOD(Get_c_from_str_aabbcd)
		{
			char str[] = "aabbcd";

			char result = GetFirstNonRepeatedChar(str);

			Assert::AreEqual('c', result);
		}
	};
}