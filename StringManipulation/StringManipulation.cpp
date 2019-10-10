#include "StringManipulation.h"
#include <iostream>
#include "crt.h"

int main()
{
	char sentence[] = "This is a simple string";
	char word[] = "string";

	char* result = mystrstr(sentence, word);
}