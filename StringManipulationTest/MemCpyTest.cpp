#include "pch.h"
#include "CppUnitTest.h"
#include "../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	TEST_CLASS(MemCpyTest)
	{
	public:
		
		TEST_METHOD(Basic_Test)
		{
			char src[] = "First";
			char dst[] = "Second";
			mymemcpy(src, dst, 3);

			Assert::AreEqual("Firond", dst);
		}
	};
}