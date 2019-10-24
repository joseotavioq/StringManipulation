#include "CppUnitTest.h"
#include "../../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	TEST_CLASS(FtoaTest)
	{
	public:

		TEST_METHOD(Convert_Simple_Number)
		{
			char text[5];
			float param = 12.9f;

			myftoa(param, text);

			Assert::AreEqual("12.9", text);
		}

		TEST_METHOD(Convert_Negative_Number)
		{
			char text[6];
			float param = -12.9f;

			myftoa(param, text);

			Assert::AreEqual("-12.9", text);
		}

		TEST_METHOD(Negative_More_Numbers_After_Period)
		{
			char text[7];
			float param = -12.19f;

			myftoa(param, text);

			Assert::AreEqual("-12.19", text);
		}

		TEST_METHOD(More_Numbers_After_Period)
		{
			char text[6];
			float param = 12.19f;

			myftoa(param, text);

			Assert::AreEqual("12.19", text);
		}
	};
}