#pragma once

struct Point { int x, y; };

/******************************************************************************
Print the word equivalent of a check amount.
ie: 1435.46  ONE THOUSAND FOUR HUNDRED THIRTY FIVE AND 46 / 100
*/
char* GetWrittenAmount(double amount);
const char* ConvertNumberToText(int number);
const char* ConvertTenToText(int number);

/******************************************************************************
GetNode all possible paths from one point to another in an array of mxn where the
number of steps from one point to the other is minimal.
Hint: Pascal triangle.
*/
unsigned int MaxPaths(Point Point1, Point Point2);    // non-recursive sol.


/******************************************************************************
In a norhteast path from one point in a greed to another, one may walk only to
the north (up) and to the east (right).  GetNode the number of NE paths from one
point to another.  O(n).
*/
unsigned int MaxNEPaths(Point point1, Point point2);    // non-recursive sol.
unsigned int MaxNEPathsBad(Point point1, Point point2); // recursive sol.


/******************************************************************************
Return the count of prime numbers from 1 to a given number.  O(n) < O(m) < O(n^2).
*/
int PrintPrimeNumbers(unsigned int number);
bool IsPrime(int n); // helper

// The Sieve of Erastothenes.
void PrintSievePrimeNumbers(unsigned int number);

/******************************************************************************
TOWERS OF HANOI - Variation using arrays.
Given an array SRC of integers sorted from larger to smaller and two other
arrays of the same size DST and TMP, move all elements from SRC to DST following
this rules: only the last element from any array can be moved at a time and the
arrays must keep sorted at all times.
See: "C++ How to program" P217 and "C++ An Introduction to Computing" P432.
*/
void HanoiMove(int size, int*& src, int*& dst, int*& tmp);


/******************************************************************************
Eight Queens Problem: Place 8 queens on an empty chessboard so that no queen
can attack any other, i.e., no two queens can be in the same row, column, or
the same diagonal.
See: "C++ How to Program" P279.
*/
void PrintChessBoard(bool ChessBoard[][8]);
bool** PlaceQueens(bool ChessBoard[][8]);


/******************************************************************************
Given the time as hour:min, find the angle between clock hands.
*/
float GetClockHandlesAngle(unsigned int hours, unsigned int minutes);

/******************************************************************************
GetNode the minimum number of cuts needed to be done on a chain so that all the
numbers from 1 to the number of links in the chain can be represented with the
resulting chain pieces.  For example: cutting a 7-link chain so that three pieces
of 1, 2 and 4 links can be used to represent all numbers from 1 to 7.
*/
unsigned FindChainCuts(unsigned chainLinks);

/******************************************************************************
A celebrity is a person among a group of people that does not know anybody in
the group but everybody knows him.  Non-celebrity people may or may not know
each other.
A Person class defines the following method:
bool Knows(Person& p), this method returns true if the object knows Person p.
Given an array of Person objects where one and only one is a celebrity,
write a function to find the celebrity.  O(n).
*/
#ifdef SAMPLE_CODE
int FindCelebrity(CPerson arrp[], int n)
{
	int iCurrCeleb = 0; // let's assume that the celebrity is in the first position in the array.

	for (int i = i; i < n - 1; i++)
	{
		if (arrp[iCurrCeleb].Knows(arrp[i]))
		{
			// arrp[iCurrCeleb] does know someone, thus he cannot be the 
			// celebrity, let's then assume the celebrity is that person               
			iCurrCeleb = i;
		}
		else
		{
			// arrp[iCurrCeleb] does not know the person after him
			// we can still assume he is the celebrity
			// however we do know that arrp[i] cannot possibly
			// be the celebrity because arrp[iCurrCeleb] does not know
			// him, we can safely disregard him             
			;
		}
	}
}


/******************************************************************************
TicTacToe see Data Structure Using C, page 303
*/
class TicTacToe
{
private:
	struct Node
	{
		char board[3][3];
		Node* firstChild;
		Node* firstSibbling;
	};
	Node* root;

	// Rotate a board so that col 1 becomes row 2 - to be used with the Equivalent method.
	void Rotate(char c[3][3], bool forward);

	// Checks if two boards are equals
	bool Equals(char c1[3][3], char c2[3][3]);

	// Checks if two boards are equivalent by rotating one of them.
	bool Equivalents(char c1[3][3], char c2[3][3]);

	// creates the board options tree
	void CreateTree();

	// paints the board with updated info.
	void UpdateBoard();
	void GetNextUserMove();

public:
	// ctr - complexity determines how deep the program will search the ttt tree to get
	// the system's next step.
	TicTacToe(int complexity);

	// Sets the users next step
	void SetMove();
}

#endif


/******************************************************************************
Get a^b % c  - w/o overflow
*/
int GetModDiv(int base, int power, int mod, int& loopCount);