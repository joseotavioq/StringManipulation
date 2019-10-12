#include "pch.h"
#include "CppUnitTest.h"
#include "../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	TEST_CLASS(SwapCharsTest)
	{
	public:

		TEST_METHOD(Swap_Chars)
		{
			char sentence[] = "This is a simple string";

			swapchars(sentence, 5, 12);

			Assert::AreEqual("This ms a siiple string", sentence);
		}
	};
}