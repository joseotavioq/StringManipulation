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
	std::cout << mytolower('J') << mytolower('o') << mytolower('S') << mytolower('e') << "\n\n";
}

void CallMyToUpper()
{
	std::cout << "[TOUPPER]\n";
	std::cout << mytoupper('J') << mytoupper('o') << mytoupper('S') << mytoupper('e') << "\n\n";
}

void CallMyMemCpy()
{
	char src[] = "First";
	char dst[] = "Second";
	mymemcpy(src, dst, 3);

	printf("src: %s\n", src);
	printf("dst: %s\n\n", dst);
}