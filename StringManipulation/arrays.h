#pragma once

///////////////////////////////////////////////////////////////////////////////
// BIT OPERATIONS AND ARRAY EXERCISES =================================

/******************************************************************************
Returns the binary representation of an integer, separating the bytes.
ie: PrintBits( 65000 ) == 1111 1101 1110 1000
*/
char* PrintBits(unsigned int number);

/******************************************************************************
Get the count of bits set in a register (use unsigned char for convenience).
O(n).
Use a lookup table to perform in O(1).
*/
unsigned int GetBitSetCount(unsigned long reg);

/******************************************************************************
Implement a BoolArray class optimized for space. Provide set/reset/get operations
on O(n).
A bit vector (bit-map) is a 32-bit int where every bit represents an entry in
the vector.
*/
class BoolArray
{
	unsigned int* m_Array;
	unsigned int  m_size;
	unsigned int  m_bitmaps;

public:
	BoolArray(unsigned int size);
	void Set(unsigned int index);
	void Reset(unsigned int index);
	bool Get(unsigned int index);
};

/******************************************************************************
Get the subvector in a vector of integers that maximizes the sum of contiguous
elements and the value of the sum.   O( n^2)
ie: A[] = { 1, -2, 3, 4 }  maxsumvec( A ) ==> position( 2, 3 ), max = 7
*/
struct VectorInfo { int StartIndex; int Count; int Sum; VectorInfo(int, int, int); };
VectorInfo* GetMaxSumVector_n2(int A[], unsigned int size);

/******************************************************************************
Get the subvector in a vector of integers with maximum positive sum of
contiguous elements and the value of the sum. If max sum is negative or zero,
it is assumed that the subvector is the empty space with sum 0.  O( n )
*/
VectorInfo* GetMaxSumVector_n(int A[], unsigned int size);

// helper function
void PrintVector(int A[], unsigned int lowPos, unsigned int hiPos, int maxSum, bool printNegative);

/******************************************************************************
Given an array of integers with posible repeated consecutive values, compress
the array so that no values are repeated.
*/
void CompressArray(int Array[], unsigned int& size);

/******************************************************************************
Given an array of integers with posible repeated non-consecutive values, compress
the array so that no values are repeated.
*/
void CompressArrayEx(int Array[], unsigned int& size);

/******************************************************************************
Having three arrays A, B, C of sorted integers and of size a, b, c respectively
,and where c = a + b; copy A and B into C keeping C sorted in linear time.
O(m+n).
To add complexity, make a & b with non-repeated numbers and C should also keep
this property.
*/
int* CopyArrays(int A[], unsigned int a, int B[], unsigned int b, int* C);

/******************************************************************************
Given an array of integers from 0 to n that contains just one duplicate value,
find that value.
*/
int GetDup(int a[], int size);

/******************************************************************************
Given an array of contiguous integers from 0 to n that contains just one duplicate value,
find that value index.
*/
int GetContiguousDup_n_formula(int a[], int size);
int GetContiguousDup_nlogn_loop(int a[], int size);
int GetContiguousDup_nlogn_recursive(int a[], int size, int offset = 0);

/******************************************************************************
Given an image file composed of pixels of 24-bit colors, find the maximum number
of repeated colors in the image.  What if the image is huge?
*/
int GetMaxRepeatedColor(void* imageDataBuffer, unsigned size);