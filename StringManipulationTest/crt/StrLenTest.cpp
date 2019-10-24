#include "CppUnitTest.h"
#include "../../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	namespace CRT
	{
		TEST_CLASS(StrLenTest)
		{
		public:

			TEST_METHOD(Count_Elements_In_Char_Array)
			{
				char mystr[] = "abc def ghi";

				int result = mystrlen(mystr);

				Assert::AreEqual(11, result);
			}

			TEST_METHOD(Count_Elements_In_A_Pre_Size_Defined_Array)
			{
				char mystr[10] = "ab";

				int result = mystrlen(mystr);

				Assert::AreEqual(2, result);
			}
		};
	}
}