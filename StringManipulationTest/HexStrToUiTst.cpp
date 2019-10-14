#include "pch.h"
#include "CppUnitTest.h"
#include "../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	TEST_CLASS(HexStrToUiTst)
	{
	public:

		TEST_METHOD(Convert_0x00A1_To_Int)
		{
			char value[] = "0x00A1";

			int result = hexstrtoui(value);

			Assert::AreEqual(161, result);
		}

		TEST_METHOD(Convert_0x9A82_To_Int)
		{
			char value[] = "0x9a82";

			int result = hexstrtoui(value);

			Assert::AreEqual(39554, result);
		}

		TEST_METHOD(Convert_0xB28_To_Int)
		{
			char value[] = "0xB28";

			int result = hexstrtoui(value);

			Assert::AreEqual(2856, result);
		}

		TEST_METHOD(Convert_0x25_To_Int)
		{
			char value[] = "0x25";

			int result = hexstrtoui(value);

			Assert::AreEqual(37, result);
		}
	};
}