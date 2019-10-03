#include "StringManipulation.h"
#include <iostream>
#include "crt.h"

int main()
{
	CallMyToLower();

	CallMyToUpper();

	CallMyMemCpy();
}

void CallMyToLower()
{
	std::cout << "[TOLOWER]\n";
	std::cout << "mytolower('J') = " << mytolower('J') << "\n";
	std::cout << "mytolower('o') = " << mytolower('o') << "\n";
	std::cout << "mytolower('S') = " << mytolower('S') << "\n";
	std::cout << "mytolower('e') = " << mytolower('e') << "\n\n";
}

void CallMyToUpper()
{
	std::cout << "[TOUPPER]\n";
	std::cout << "mytoupper('J') = " << mytoupper('J') << "\n";
	std::cout << "mytoupper('o') = " << mytoupper('o') << "\n";
	std::cout << "mytoupper('S') = " << mytoupper('S') << "\n";
	std::cout << "mytoupper('e') = " << mytoupper('e') << "\n\n";
}

void CallMyMemCpy()
{
	char src[] = "ABC";
	char dst[4];
	mymemcpy(src, dst, 3);

	std::cout << "[TOUPPER]\n";
	std::cout << "char src[] = \"ABC\";\n";
	std::cout << "char dst[4];\n";
	std::cout << "mymemcpy(src, dst, 3); dst = " << dst << "\n";
}