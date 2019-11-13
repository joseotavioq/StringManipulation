#include "CppUnitTest.h"
#include "../../StringManipulation/Exercises.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	namespace Exercises
	{
		TEST_CLASS(GetClockHandlesAngleTest)
		{
		public:

			TEST_METHOD(Angle_For_15_OClock_Is_90)
			{
				float result = GetClockHandlesAngle(15, 0);

				Assert::AreEqual(90.0f, result);
			}

			TEST_METHOD(Angle_For_14_OClock_Is_60)
			{
				float result = GetClockHandlesAngle(14, 0);

				Assert::AreEqual(60.0f, result);
			}

			TEST_METHOD(Angle_For_18_OClock_Is_180)
			{
				float result = GetClockHandlesAngle(18, 0);

				Assert::AreEqual(180.0f, result);
			}

			TEST_METHOD(Angle_For_20_And_15_Is_157_5)
			{
				float result = GetClockHandlesAngle(20, 15);

				Assert::AreEqual(157.5f, result);
			}

			TEST_METHOD(Angle_For_3_And_10_Is_35)
			{
				float result = GetClockHandlesAngle(3, 10);

				Assert::AreEqual(35.0f, result);
			}
		};
	}
}