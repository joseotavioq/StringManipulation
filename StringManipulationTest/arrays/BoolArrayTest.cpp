#include "CppUnitTest.h"
#include "../../StringManipulation/arrays.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	namespace Arrays
	{
		TEST_CLASS(BoolArrayTest)
		{
		public:

			TEST_METHOD(Create_A_Simple_Object_Set_Index_And_Get_It)
			{
				BoolArray* test = new BoolArray(5);

				test->Set(3);
				bool valueOfFive = test->Get(3);

				Assert::AreEqual(true, valueOfFive);
			}

			TEST_METHOD(Create_A_Simple_Object_And_Get_Any_Index)
			{
				BoolArray* test = new BoolArray(5);

				bool valueOfFive = test->Get(3);

				Assert::AreEqual(false, valueOfFive);
			}

			TEST_METHOD(Create_A_Simple_Object_Set_Index_Reset_And_Get_It)
			{
				BoolArray* test = new BoolArray(5);

				test->Set(3);
				test->Reset(3);
				bool valueOfFive = test->Get(3);

				Assert::AreEqual(false, valueOfFive);
			}
		};
	}
}