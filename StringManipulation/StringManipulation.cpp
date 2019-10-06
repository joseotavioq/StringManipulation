#include "StringManipulation.h"
#include <iostream>
#include "crt.h"

int main()
{
	char str[] = "abc def ghi jkl mno";

	mymemmove(str + 4, str + 8, 11);
}