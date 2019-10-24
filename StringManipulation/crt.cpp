#include "crt.h"
#include <stdlib.h>

char mytolower(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return ch + ('a' - 'A');
	else
		return ch;
}

char mytoupper(char ch)
{
	if (ch >= 'a' && ch <= 'z')
		return ch - ('a' - 'A');
	else
		return ch;
}

void* mymemcpy(void* src_, void* dst_, unsigned int count)
{
	char* srcChar = (char*)src_;
	char* dstChar = (char*)dst_;

	for (size_t i = 0; i < count; i++)
	{
		*(dstChar + i) = *(srcChar + i);
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


void* mymemmove_without_memory_allocation(void* src_, void* dst_, unsigned int count)
{
	char* src = (char*)src_;
	char* dst = (char*)dst_;

	if (dst > src)
	{
		while (count--)
		{
			*(dst + count) = *(src + count);
		}
	}
	else
	{
		int index = 0;

		while (count--)
		{
			*(dst + index) = *(src + index);
			index++;
		}
	}

	return dst_;
}

void* mymemset(void* dest, char c, unsigned count)
{
	char* dstChar = (char*)dest;

	for (size_t i = 0; i < count; i++)
	{
		*(dstChar + i) = c;
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
	const char* initial = str;

	while (*str != '\0') { str++; }

	return str - initial;
}

char* mystrcpy(char* dst, const char* src)
{
	do
	{
		char* srcChar = (char*)src;
		char* dstChar = dst;
		*dstChar = *srcChar;
		dst++;
	} while (*src++);

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
	} while (*str1++);

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
	} while (*src++);

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

		strChar++;
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

		strChar++;
	}

	//for the null termination char
	if (*strChar == ch)
		return strChar;

	return nullptr;
}

int mystrspn_bigO_of_n_m(const char* str, const char* strCharSet)
{
	char* initialPointer = (char*)str;

	while (*str)
	{
		char* cset = (char*)strCharSet;
		while (*cset)
		{
			if (*str == *cset)
				break;

			cset++;
		}

		if (!*cset)
			break;

		str++;
	}

	return str - initialPointer;
}

int mystrspn_bigO_of_n(const char* str, const char* strCharSet)
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
	int index = 0;
	int result = ival;

	if (ival < 0)
	{
		*szval = '-';
		index++;
		result *= -1;
	}

	do
	{
		int num = result % 10;
		*(szval + index) = '0' + num;
		index++;
		result /= 10;
	} while (result != 0);

	*(szval + index) = '\0';

	szval = revstr(szval + (ival < 0 ? 1 : 0));
}

void myftoa(const float fval, char* szval)
{
	int index = 0;

	int posOfPeriod = 0;
	float onlyDecimal = fval;
	int result = (int)onlyDecimal;

	if (result < 0)
	{
		*szval = '-';
		index++;
		result *= -1;
		onlyDecimal *= -1;
		posOfPeriod++;
	}

	while (onlyDecimal - result > 0)
	{
		onlyDecimal *= 10;
		posOfPeriod++;
		result = (int)onlyDecimal;
	}

	do
	{
		if (posOfPeriod == index)
		{
			*(szval + index) = '.';
			index++;
		}

		int num = result % 10;
		*(szval + index) = '0' + num;
		index++;
		result /= 10;
	} while (result != 0);

	*(szval + index) = '\0';

	szval = revstr(szval + (fval < 0 ? 1 : 0));
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
	float result = 0;
	bool convertToNegative = false;
	bool convertToDecimal = false;
	int div = 10;

	while (*str != '\0')
	{
		if (*str == '-')
			convertToNegative = true;
		else if (*str == '.')
			convertToDecimal = true;
		else if (*str >= '0' && *str <= '9')
			if (convertToDecimal)
			{
				float decimal = ((float)(*str - '0')) / div;
				result += decimal;
				div *= 10;
			}
			else
				result = result * 10 + (*str - '0');

		str++;
	}

	if (convertToNegative)
		result = result * -1;

	return result;
}

char* itostrhex(unsigned int ival, char* str)
{
	int index = 0;

	while (ival > 0)
	{
		int mod = ival % 16;

		if (mod >= 10 && mod <= 15)
			*(str + index) = ('A' + mod) - 10;
		else
			*(str + index) = '0' + mod;

		ival = ival / 16;

		index++;
	}

	*(str + index) = '\0';

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
	char* initial = str;

	do
	{
		int mod = ival % 2;
		ival /= 2;

		*str = mod + '0';
		str++;
	} while (ival > 0);

	*str = '\0';

	return revstr(initial);
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
	char* newStr = str;

	for (size_t i = 0; *(str + i) != '\0'; i++)
	{
		bool ctrlFound = false;
		for (size_t j = 0; j < size; j++)
		{
			if (*(str + i) == ctrl[j])
			{
				ctrlFound = true;
				break;
			}
		}

		if (!ctrlFound)
		{
			*newStr = *(str + i);
			newStr++;
		}
	}

	*newStr = '\0';

	return str;
}

char* insertstr(char* dst, const char* src, unsigned int pos)
{
	unsigned int length = mystrlen(src);

	void* tmp = malloc(sizeof(char) * length);

	if (tmp != NULL)
	{
		for (size_t i = 0; i < length; i++)
		{
			char* srcChar = (char*)src + i;
			char* tmpChar = (char*)tmp + i;
			*tmpChar = *srcChar;
		}

		for (size_t i = 0; i < length; i++)
		{
			char* tmpChar = (char*)tmp + i;
			char* dstChar = (char*)dst + pos + i;

			if (*dstChar == '\0')
				break;

			*dstChar = *tmpChar;
		}

		free(tmp);
	}

	return dst;
}

char* rotstr(char* str)
{
	char firstChar = *str;

	int i = 0;
	while (*(str + i))
	{
		if (*(str + i + 1) == '\0')
			*(str + i) = firstChar;
		else
			*(str + i) = *(str + i + 1);

		i++;
	}

	return str;
}

char* rotnstr(char* str, unsigned int n)
{
	char firstChar = *str;

	int i = 0;
	while (*(str + i) && n > 0)
	{
		if (*(str + i + 1) == '\0')
		{
			*(str + i) = firstChar;
			n--;
			i = 0;
			firstChar = *str;
			continue;
		}
		else
			*(str + i) = *(str + i + 1);

		i++;
	}

	return str;
}

char* rotchars(char ch[], unsigned int len)
{
	char firstChar = ch[0];

	for (size_t i = 0; i < len; i++)
	{
		if (i == len - 1)
			ch[i] = firstChar;
		else
			ch[i] = ch[i + 1];
	}

	return ch;
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