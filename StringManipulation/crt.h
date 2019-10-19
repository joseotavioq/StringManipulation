/*
	CRT fundamental functions by Miguel Lacouture.
	CRT = C Run-Time
*/

#include <stdio.h>
#include <assert.h>

////////////////////////////////////////////////////////////////////////
/////////////////  TOLOWER - TOUPPER

char mytolower(char ch);
char mytoupper(char ch);

////////////////////////////////////////////////////////////////////////
/////////////////  MEMCPY - MEMMOVE - MEMSET
//
// dst must have enough room to hold count chars from src.
//
void* mymemcpy(void* src_, void* dst_, unsigned int count);
void* mymemmove(void* src_, void* dst_, unsigned int count);
void* mymemmove_without_memory_allocation(void* src_, void* dst_, unsigned int count);
void* mymemset(void* dest, char c, unsigned count);

////////////////////////////////////////////////////////////////////////
/////////////////  STRNCPY, STRNCMP, STRNCAT
//
// dst must have enough room to hold count chars from src.
//
char* mystrncpy(char* dst, const char* src, unsigned int count);
int   mystrncmp(const char* str1, const char* str2, unsigned int count);
char* mystrncat(char* dst, char const* src, unsigned int count);

////////////////////////////////////////////////////////////////////////
/////////////////  STRLEN, STRCPY, STRCMP, STRICMP, STRCAT, STRSTR, STRISTR, ...

unsigned int mystrlen(char const* str);
char* mystrcpy(char* dst, const char* src);
int	  mystrcmp(const char* str1, const char* str2);
int	  mystricmp(const char* str1, const char* str2);
char* mystrcat(char* dst, const char* src);
char* mystrstr(const char* str1, const char* str2);	// GetNode a substring
char* mystrrchr(const char* str, int ch); // Scan a string for the last occurrence of a character
char* mystrchr(const char* str, int ch); // search a string for a character
int   mystrspn_bigO_of_n_m(const char* str, const char* strCharSet); //Returns an integer value specifying the length of the substring in string that consists entirely of characters in strCharSet
int   mystrspn_bigO_of_n(const char* str, const char* strCharSet);

////////////////////////////////////////////////////////////////////////
/////////////////  ITOA, DTOA, ATOI, ATOF
void  myitoa(const int   ival, char* szval);
void  myftoa(const float fval, char* szval);
int   myatoi(char* str);
float myatof(char* str);

///////////////////////////////////////////////////////////////////////////////
// 2. STRING EXERCISES =================================


/******************************************************************************
Convert an integer to its hexadecimal string representation.
*/
char* itostrhex(unsigned int ival, char* str);

/******************************************************************************
Convert string representing a hex number to its uint corresponding value.
ex: hexstrtoui( "0x00A1" ) == 161
*/
unsigned int hexstrtoui(char* str);

/******************************************************************************
Convert an integer to its binary string representation.
*/
char* itostrbin(unsigned int ival, char* str);

/******************************************************************************
Revert the characters in a string.  rev( "abc" ) == "cba".
*/
char* revstr(char* str);

/******************************************************************************
Revert the characters of a portion of a string (substring).
revsubstr( "abcefg", 1, 3 ) == "aecbfg".
*/
char* revsubstr(char* str, unsigned int pos, unsigned int len);

/******************************************************************************
Revert the words in a string.  rev( "The cat and the dog" ) == "dog the and cat The".
*/
char* revwrd(char* str);

/******************************************************************************
Remove a substring of length 'count' starting at position 'pos' from a string.
*/
char* remstr(char* str, unsigned int pos, unsigned int count);

/******************************************************************************
Remove instances of characters specified in 'ctrl' from string. O(mn)
Can be O(m + n) if ctrl array is a lookup table build in O(m).
*/
char* remchars(char* str, char ctrl[], unsigned int size);

/******************************************************************************
Insert a string into another string at an specified position.
*/
char* insertstr(char* dst, const char* src, unsigned int pos);

/******************************************************************************
Rotate-left characters in a string.
*/
char* rotstr(char* str);

/******************************************************************************
Rotate-left n characters in a string. O(n)
*/
char* rotnstr(char* str, unsigned int n);

/******************************************************************************
Shift-left characters in a portion of a char array specified by a length from
the first element.
*/
char* rotchars(char ch[], unsigned int len);

/******************************************************************************
swap characters at specified locations.
*/
void swapchars(char* str, int pos1, int pos2);

/******************************************************************************
GetNode the first non-repeated character in a string. i.e.: f("total") == 'o'  O(n)
*/
char GetFirstNonRepeatedChar(const char* str);