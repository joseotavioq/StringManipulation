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
		char* dstChar = dst + i;

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
			char* dstChar = dst + i;
			char* tmpChar = (char*)tmp + i;
			*tmpChar = *dstChar;
		}

		unsigned int countOfItensOnSource = 0;
		for (size_t i = 0; i < count; i++)
		{
			char* srcChar = (char*)src + i;

			if (*srcChar == '\0')
				break;

			char* dstChar = dst + i;
			*dstChar = *srcChar;

			countOfItensOnSource++;
		}

		unsigned int t = 0;
		for (size_t i = countOfItensOnSource; i < dstLength; i++)
		{
			char* tmpChar = (char*)tmp + t;
			char* dstChar = dst + i;
			*dstChar = *tmpChar;
			t++;
		}

		*(dst + dstLength) = '\0';

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
		char currentCharFirst = *str1;
		char currentCharSecond = *str2;

		if (currentCharFirst > currentCharSecond || currentCharFirst < currentCharSecond)
		{
			return currentCharFirst - currentCharSecond;
		}

		str2++;
	} while ((*(str1++) != '\0'));

	return 0;
}

int mystricmp(const char* str1, const char* str2)
{
	do
	{
		char currentCharFirst = *str1;
		char currentCharSecond = *str2;

		char first = mytolower(currentCharFirst);
		char second = mytolower(currentCharSecond);

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

	char* startAtChar = dst + dstLength;

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
	char str1Char = *str1;
	char str2Char = *str2;

	int numberOfEqualCharacters = 0;
	int str2Length = mystrlen(str2);

	while (str1Char != '\0')
	{
		if (str1Char == str2Char)
			numberOfEqualCharacters++;
		else if (numberOfEqualCharacters == str2Length)
			return (char*)str1 - numberOfEqualCharacters;
		else
			numberOfEqualCharacters = 0;

		str1++;

		str1Char = *str1;
		str2Char = *(str2 + numberOfEqualCharacters);
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
	size_t strCharSetLength = mystrlen(strCharSet);
	for (size_t i = 0; i < strCharSetLength; i++)
	{
		char strChar = *(strCharSet + i);
		asciiTable[strChar] = strChar;
	}

	int elementsFound = 0;
	char strChar = *str;
	while (strChar != '\0')
	{
		if (asciiTable[strChar] == strChar)
			elementsFound++;

		str++;
		strChar = *str;
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
	bool convertToNegative = false;

	while (*str != '\0')
	{
		if (*str == '-')
			convertToNegative = true;
		else if (*str >= '0' && *str <= '9')
			result = result * 10 + (*str - '0');

		str++;
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
	int index = 0;
	char* strChar = str;

	while (ival > 0)
	{
		strChar = str + index;

		int mod = ival % 16;

		if (mod >= 10 && mod <= 15)
			* strChar = ('A' + mod) - 10;
		else
			*strChar = '0' + mod;

		ival = ival / 16;

		index++;
	}

	strChar = str + index;
	*strChar = '\0';

	str = revstr(str);

	return str;
}

unsigned int hexstrtoui(char* str)
{
	int result = 0;

	//skip 0x
	str = str + 2;
	size_t length = mystrlen(str) - 1;

	while (*str != '\0')
	{
		int value = 0;

		if (*str >= '0' && *str <= '9')
			value = *str - '0';
		else if ((*str >= 'A' && *str <= 'F'))
			value = 10 + (*str - 'A');
		else if ((*str >= 'a' && *str <= 'f'))
			value = 10 + (*str - 'a');

		if (value > 0)
		{
			int sixteenPowerOfLength = 1;

			for (size_t i = 0; i < length; i++)
				sixteenPowerOfLength *= 16;

			result += value * sixteenPowerOfLength;
		}

		length--;
		str++;
	}

	return result;
}

char* itostrbin(unsigned int ival, char* str)
{
	return nullptr;
}

char* revstr(char* str)
{
	size_t strLength = mystrlen(str);

	for (size_t i = 0; i < strLength / 2; i++)
	{
		char* strChar = str + i;
		char* lastChar = str + strLength - 1 - i;
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
		char* strChar = str + start;
		char* lastChar = str + end;
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
	str = revstr(str);
	size_t len = mystrlen(str);

	size_t initialPositionOfAWord = 0;

	for (size_t i = 0; i <= len; i++)
	{
		char* currentChar = str + i;

		if (*currentChar == ' ' || *currentChar == '\0')
		{
			str = revsubstr(str, initialPositionOfAWord, i - initialPositionOfAWord);

			initialPositionOfAWord = i + 1;
		}
	}

	return str;
}

char* remstr(char* str, unsigned int pos, unsigned int count)
{
	int length = mystrlen(str);

	if (pos + count == length)
	{
		char* strChar = str + pos;
		*strChar = '\0';
		return str;
	}

	mymemmove(str + pos + count, str + pos, length - (pos + count));

	char* strChar = str + length - count;
	*strChar = '\0';

	return str;
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
	char* pos1Char = str + pos1;
	char* pos2Char = str + pos2;
	char tmp = *pos1Char;
	*pos1Char = *pos2Char;
	*pos2Char = tmp;
}

char GetFirstNonRepeatedChar(const char* str)
{
	int asciiTable[128] = { 0 };

	int index = 0;
	char* strChar = (char*)str;

	while (*strChar != '\0')
	{
		asciiTable[*strChar]++;

		index++;
		strChar = (char*)str + index;
	}

	index = 0;
	strChar = (char*)str;

	while (*strChar != '\0')
	{
		if (asciiTable[*strChar] == 1)
			return *strChar;

		index++;
		strChar = (char*)str + index;
	}

	return '\0';
}