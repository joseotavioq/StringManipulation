#include "CppUnitTest.h"
#include "../../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	namespace CRT
	{
		TEST_CLASS(ToLowerTest)
		{
		public:

			TEST_METHOD(With_UpperCase_Char)
			{
				char result = mytolower('J');

				Assert::AreEqual('j', result);
			}

			TEST_METHOD(With_LowerCase_Char)
			{
				char result = mytolower('j');

				Assert::AreEqual('j', result);
			}

			TEST_METHOD(Another_Char)
			{
				char result = mytolower('1');

				Assert::AreEqual('1', result);
			}
		};
	}
}