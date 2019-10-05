#include "pch.h"
#include "CppUnitTest.h"
#include "../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	TEST_CLASS(ToUpperTest)
	{
	public:
		
		TEST_METHOD(With_UpperCase_Char)
		{
			char result = mytoupper('J');

			Assert::AreEqual('J', result);
		}

		TEST_METHOD(With_LowerCase_Char)
		{
			char result = mytoupper('j');

			Assert::AreEqual('J', result);
		}

		TEST_METHOD(Another_Char)
		{
			char result = mytoupper('1');

			Assert::AreEqual('1', result);
		}
	};
}