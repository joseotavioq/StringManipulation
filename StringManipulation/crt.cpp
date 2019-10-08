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
	return 0;
}

int mystricmp(const char* str1, const char* str2)
{
	return 0;
}

char* mystrcat(char* dst, const char* src)
{
	return nullptr;
}

char* mystrstr(const char* str1, const char* str2)
{
	return nullptr;
}

char* mystrrchr(const char* str, int ch)
{
	return nullptr;
}

char* mystrchr(const char* str, int ch)
{
	return nullptr;
}

int mystrspn(const char* str, const char* strCharSet)
{
	return 0;
}

void myitoa(const int ival, char* szval)
{
}

void myftoa(const float fval, char* szval)
{
}

int myatoi(char* str)
{
	return 0;
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
	return 0;
}

char* itostrbin(unsigned int ival, char* str)
{
	return nullptr;
}

char* revstr(char* str)
{
	return nullptr;
}

char* revsubstr(char* str, unsigned int pos, unsigned int len)
{
	return nullptr;
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
}

char GetFirstNonRepeatedChar(const char* str)
{
	return 0;
}