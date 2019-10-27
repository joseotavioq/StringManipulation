#include "arrays.h"
#include "crt.h"
#include <stdlib.h>

char* PrintBits(unsigned int number)
{
	void* tmp = malloc(sizeof(char) * 20);

	if (tmp != NULL)
	{
		char* tmpChar = (char*)tmp;

		int index = 0;
		int includeSpace = 0;
		while (number > 0)
		{
			if (includeSpace == 4)
			{
				*(tmpChar + index) = ' ';
				index++;
				includeSpace = 0;
			}
			includeSpace++;

			int mod = number % 2;
			number /= 2;

			*(tmpChar + index) = mod + '0';
			index++;
		}

		*(tmpChar + index) = '\0';

		return revstr(tmpChar);
	}

	return nullptr;
}

unsigned int GetBitSetCount(unsigned long reg)
{
	return 0;
}


BoolArray::BoolArray(unsigned int size)
{
	m_Array = 0;
	m_size = size;
	m_bitmaps = 0;
}

void BoolArray::Set(unsigned int index)
{

}

void BoolArray::Reset(unsigned int index)
{

}

bool BoolArray::Get(unsigned int index)
{
	return true;
}

VectorInfo* GetMaxSumVector_n2(int A[], unsigned int size)
{
	return nullptr;
}

VectorInfo* GetMaxSumVector_n(int A[], unsigned int size)
{
	return nullptr;
}

void PrintVector(int A[], unsigned int lowPos, unsigned int hiPos, int maxSum, bool printNegative)
{

}

void CompressArray(int Array[], unsigned int& size)
{

}

void CompressArrayEx(int Array[], unsigned int& size)
{

}

int* CopyArrays(int A[], unsigned int a, int B[], unsigned int b, int* C)
{
	return 0;
}

int GetDup(int a[], int size)
{
	return 0;
}

int GetContiguousDup_n_formula(int a[], int size)
{
	return 0;
}

int GetContiguousDup_nlogn_loop(int a[], int size)
{
	return 0;
}

int GetContiguousDup_nlogn_recursive(int a[], int size, int offset)
{
	return 0;
}

int GetMaxRepeatedColor(void* imageDataBuffer, unsigned size)
{
	return 0;
}