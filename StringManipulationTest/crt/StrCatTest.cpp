#include "CppUnitTest.h"
#include "../../StringManipulation/crt.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StringManipulationTest
{
	namespace CRT
	{
		TEST_CLASS(StrCatTest)
		{
		public:

			TEST_METHOD(Cat_Two_Strings)
			{
				char str1[19];
				mystrcpy(str1, "To be ");
				char str2[] = "or not to be";

				mystrcat(str1, str2);

				Assert::AreEqual("To be or not to be", str1);
			}

			TEST_METHOD(Complex_Cat)
			{
				char str[80];
				mystrcpy(str, "these ");
				mystrcat(str, "strings ");
				mystrcat(str, "are ");
				mystrcat(str, "concatenated.");

				Assert::AreEqual("these strings are concatenated.", str);
			}
		};
	}
}