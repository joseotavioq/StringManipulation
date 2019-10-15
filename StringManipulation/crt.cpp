#include "crt.h"
#include <stdlib.h>

char mytolower(char ch)
{
	if (ch >= 65 && ch <= 90)
		return ch + 32;
	else
		return ch;
}

char mytoupper(char ch)
{
	if (ch >= 97 && ch <= 122)
		return ch - 32;
	else
		return ch;
}

void* mymemcpy(void* src_, void* dst_, unsigned int count)
{
	for (size_t i = 0; i < count; i++)
	{
		char* srcChar = (char*)src_ + i;
		char* dstChar = (char*)dst_ + i;
		*dstChar = *srcChar;
	}

	return dst_;
}

void* mymemmove(void* src_, void* dst_, unsigned int count)
{
	void* tmp = malloc(sizeof(char) * count);

	if (tmp != NULL)
	{
		for (size_t i = 0; i < count; i++)
		{
			char* srcChar = (char*)src_ + i;
			char* tmpChar = (char*)tmp + i;
			*tmpChar = *srcChar;
		}

		for (size_t i = 0; i < count; i++)
		{
			char* tmpChar = (char*)tmp + i;
			char* dstChar = (char*)dst_ + i;
			*dstChar = *tmpChar;
		}

		free(tmp);
	}

	return dst_;
}

void* mymemset(void* dest, char c, unsigned count)
{
	for (size_t i = 0; i < count; i++)
	{
		char* dstChar = (char*)dest + i;
		*dstChar = c;
	}

	return dest;
}

char* mystrncpy(char* dst, const char* src, unsigned int count)
{
	bool foundTheEndOfString = false;
	for (size_t i = 0; i < count; i++)
	{
		char* srcChar = (char*)src + i;
		char* dstChar = (char*)dst + i;

		if (*srcChar == '\0')
		{
			*dstChar = '\0';
			foundTheEndOfString = true;
		}
		else if (foundTheEndOfString)
		{
			*dstChar = '0';
		}
		else
		{
			*dstChar = *srcChar;
		}
	}

	return dst;
}

int mystrncmp(const char* str1, const char* str2, unsigned int count)
{
	for (size_t i = 0; i < count; i++)
	{
		char* currentCharFirst = (char*)str1 + i;
		char* currentCharSecond = (char*)str2 + i;

		if (*currentCharFirst > * currentCharSecond || *currentCharFirst < *currentCharSecond)
		{
			return *currentCharFirst - *currentCharSecond;
		}
		else if (*currentCharFirst == '\0' || *currentCharSecond == '\0')
		{
			return 0;
		}
	}

	return 0;
}

char* mystrncat(char* dst, char const* src, unsigned int count)
{
	unsigned int dstLength = mystrlen(dst);

	void* tmp = malloc(sizeof(char) * dstLength);

	if (tmp != NULL)
	{
		for (size_t i = 0; i < dstLength; i++)
		{
			char* dstChar = (char*)dst + i;
			char* tmpChar = (char*)tmp + i;
			*tmpChar = *dstChar;
		}

		unsigned int countOfItensOnSource = 0;
		for (size_t i = 0; i < count; i++)
		{
			char* srcChar = (char*)src + i;

			if (*srcChar == '\0')
				break;

			char* dstChar = (char*)dst + i;
			*dstChar = *srcChar;

			countOfItensOnSource++;
		}

		unsigned int t = 0;
		for (size_t i = countOfItensOnSource; i < dstLength; i++)
		{
			char* tmpChar = (char*)tmp + t;
			char* dstChar = (char*)dst + i;
			*dstChar = *tmpChar;
			t++;
		}

		*((char*)dst + dstLength) = '\0';

		free(tmp);

		return dst;
	}

	return nullptr;
}

unsigned int mystrlen(char const* str)
{
	int length = 0;

	while (*(str + length) != '\0')
		length++;

	return length;
}

char* mystrcpy(char* dst, const char* src)
{
	do
	{
		char* srcChar = (char*)src;
		char* dstChar = dst;
		*dstChar = *srcChar;
		dst++;
	} while ((*(src++) != '\0'));

	return dst;
}

int mystrcmp(const char* str1, const char* str2)
{
	do
	{
		char* currentCharFirst = (char*)str1;
		char* currentCharSecond = (char*)str2;

		if (*currentCharFirst > * currentCharSecond || *currentCharFirst < *currentCharSecond)
		{
			return *currentCharFirst - *currentCharSecond;
		}

		str2++;
	} while ((*(str1++) != '\0'));

	return 0;
}

int mystricmp(const char* str1, const char* str2)
{
	do
	{
		char* currentCharFirst = (char*)str1;
		char* currentCharSecond = (char*)str2;

		char first = mytolower(*currentCharFirst);
		char second = mytolower(*currentCharSecond);

		if (first > second || first < second)
		{
			return first - second;
		}

		str2++;
	} while ((*(str1++) != '\0'));

	return 0;
}

char* mystrcat(char* dst, const char* src)
{
	unsigned int dstLength = mystrlen(dst);

	char* startAtChar = (char*)dst + dstLength;

	do {
		char* srcChar = (char*)src;
		char* dstChar = startAtChar;
		*dstChar = *srcChar;

		startAtChar++;
	} while ((*(src++) != '\0'));

	return dst;
}

char* mystrstr(const char* str1, const char* str2)
{
	char* str1Char = (char*)str1;
	char* str2Char = (char*)str2;

	int numberOfEqualCharacters = 0;
	int str2Length = mystrlen(str2);

	while (*str1Char != '\0')
	{
		if (*str1Char == *str2Char)
			numberOfEqualCharacters++;
		else if (numberOfEqualCharacters == str2Length)
			return (char*)str1 - numberOfEqualCharacters;
		else
			numberOfEqualCharacters = 0;

		str1++;

		str1Char = (char*)str1;
		str2Char = (char*)str2 + numberOfEqualCharacters;
	}

	if (numberOfEqualCharacters == str2Length)
		return (char*)str1 - numberOfEqualCharacters;

	return nullptr;
}

char* mystrrchr(const char* str, int ch)
{
	char* strChar = (char*)str;
	char* lastCharFound = nullptr;

	while (*strChar != '\0')
	{
		if (*strChar == ch)
			lastCharFound = strChar;

		str++;
		strChar = (char*)str;
	}

	//for the null termination char
	if (*strChar == ch)
		return strChar;
	else if (lastCharFound != nullptr)
		return lastCharFound;

	return nullptr;
}

char* mystrchr(const char* str, int ch)
{
	char* strChar = (char*)str;

	while (*strChar != '\0')
	{
		if (*strChar == ch)
			return strChar;

		str++;
		strChar = (char*)str;
	}

	//for the null termination char
	if (*strChar == ch)
		return strChar;

	return nullptr;
}

int mystrspn(const char* str, const char* strCharSet)
{
	char asciiTable[128] = { '\0' };
	int strCharSetLength = mystrlen(strCharSet);
	for (size_t i = 0; i < strCharSetLength; i++)
	{
		char* strChar = (char*)strCharSet + i;
		asciiTable[*strChar] = *strChar;
	}

	int elementsFound = 0;
	char* strChar = (char*)str;
	while (*strChar != '\0')
	{
		if (asciiTable[*strChar] == *strChar)
			elementsFound++;

		str++;
		strChar = (char*)str;
	}

	return elementsFound;
}

void myitoa(const int ival, char* szval)
{
}

void myftoa(const float fval, char* szval)
{
}

int myatoi(char* str)
{
	int result = 0;
	char* strChar = (char*)str;
	bool convertToNegative = false;

	while (*strChar != '\0')
	{
		if (*strChar == '-')
			convertToNegative = true;
		else if (*strChar >= '0' && *strChar <= '9')
			result = result * 10 + (*strChar - '0');

		str++;
		strChar = (char*)str;
	}

	if (convertToNegative)
		result = result * -1;

	return result;
}

float myatof(char* str)
{
	return 0.0f;
}

char* itostrhex(unsigned int ival, char* str)
{
	return nullptr;
}

unsigned int hexstrtoui(char* str)
{
	int result = 0;

	//skip 0x
	str = str + 2;
	int length = mystrlen(str) - 1;

	char* strChar = (char*)str;
	while (*strChar != '\0')
	{
		int value = 0;

		if (*strChar >= '0' && *strChar <= '9')
			value = *strChar - '0';
		else if ((*strChar >= 'A' && *strChar <= 'F'))
			value = 10 + (*strChar - 'A');
		else if ((*strChar >= 'a' && *strChar <= 'f'))
			value = 10 + (*strChar - 'a');

		if (value > 0)
		{
			int sixteenPowerOfLength = 1;

			for (size_t i = 0; i < length; i++)
				sixteenPowerOfLength *= 16;

			result += value * sixteenPowerOfLength;
		}

		length--;
		str++;
		strChar = (char*)str;
	}

	return result;
}

char* itostrbin(unsigned int ival, char* str)
{
	return nullptr;
}

char* revstr(char* str)
{
	int strLength = mystrlen(str);

	for (size_t i = 0; i < strLength / 2; i++)
	{
		char* strChar = (char*)str + i;
		char* lastChar = (char*)str + strLength - 1 - i;
		char tmp = *strChar;
		*strChar = *lastChar;
		*lastChar = tmp;
	}

	return str;
}

char* revsubstr(char* str, unsigned int pos, unsigned int len)
{
	int start = pos;
	int end = pos + len - 1;

	while (start < end)
	{
		char* strChar = (char*)str + start;
		char* lastChar = (char*)str + end;
		char tmp = *strChar;
		*strChar = *lastChar;
		*lastChar = tmp;

		start++;
		end--;
	}

	return str;
}

char* revwrd(char* str)
{
	return nullptr;
}

char* remstr(char* str, unsigned int pos, unsigned int count)
{
	return nullptr;
}

char* remchars(char* str, char ctrl[], unsigned int size)
{
	return nullptr;
}

char* insertstr(char* dst, const char* src, unsigned int pos)
{
	return nullptr;
}

char* rotstr(char* str)
{
	return nullptr;
}

char* rotnstr(char* str, unsigned int n)
{
	return nullptr;
}

char* rotchars(char ch[], unsigned int len)
{
	return nullptr;
}

void swapchars(char* str, int pos1, int pos2)
{
	char* pos1Char = (char*)str + pos1;
	char* pos2Char = (char*)str + pos2;
	char tmp = *pos1Char;
	*pos1Char = *pos2Char;
	*pos2Char = tmp;
}

char GetFirstNonRepeatedChar(const char* str)
{
	return 0;
}