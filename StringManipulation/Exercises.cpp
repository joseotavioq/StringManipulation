#include "Exercises.h"
#include "crt.h"
#include <stdlib.h>

char* GetWrittenAmount(double amount)
{
	char* tmp = new char[1024];

	int countOfDigits = 0;
	while (amount >= 1)
	{
		amount /= 10;
		countOfDigits++;
	}

	bool hasTyped = false;
	while (amount >= 0 && countOfDigits >= -1)
	{
		amount *= 10;
		int amountInt = (int)amount;

		if (amountInt > 0)
		{
			const char* nameOfNumber = "";
			const char* typeOfNumber = "";

			if (countOfDigits == 4)
			{
				nameOfNumber = ConvertNumberToText(amountInt);
				typeOfNumber = " THOUSAND";
			}
			else if (countOfDigits == 3)
			{
				nameOfNumber = ConvertNumberToText(amountInt);
				typeOfNumber = " HUNDRED";
			}
			else if (countOfDigits == 2)
			{
				nameOfNumber = ConvertTenToText(amountInt);
			}
			else if (countOfDigits == 1)
			{
				nameOfNumber = ConvertNumberToText(amountInt);
			}
			else if (countOfDigits == 0)
			{
				nameOfNumber = ConvertTenToText(amountInt);
			}
			else if (countOfDigits == -1)
			{
				nameOfNumber = ConvertNumberToText(amountInt);
			}

			if (!hasTyped)
			{
				mystrcpy(tmp, nameOfNumber);
				hasTyped = true;
			}
			else
			{
				mystrcat(tmp, " ");
				mystrcat(tmp, nameOfNumber);
			}

			mystrcat(tmp, typeOfNumber);

			amount = amount - (int)amount;
		}

		countOfDigits--;
	}

	return tmp;
}

const char* ConvertNumberToText(int number)
{
	if (number == 1)
		return "ONE";
	else if (number == 2)
		return "TWO";
	else if (number == 3)
		return "THREE";
	else if (number == 4)
		return "FOUR";
	else if (number == 5)
		return "FIVE";
	else if (number == 6)
		return "SIX";
	else if (number == 7)
		return "SEVEN";
	else if (number == 8)
		return "EIGHT";
	else if (number == 9)
		return "NINE";

	return "";
}

const char* ConvertTenToText(int number)
{
	if (number == 1)
		return "TEN";
	else if (number == 2)
		return "TWEENTY";
	else if (number == 3)
		return "THIRDY";
	else if (number == 4)
		return "FOURTHY";
	else if (number == 5)
		return "FIFTY";
	else if (number == 6)
		return "SIXTY";
	else if (number == 7)
		return "SEVENTY";
	else if (number == 8)
		return "EIGHTY";
	else if (number == 9)
		return "NINETY";

	return "";
}

void WriteCheckAmount(double amount)
{
}

void WriteHundreds(unsigned int amount)
{
}

unsigned int MaxPaths(Point Point1, Point Point2)
{
	return 0;
}

unsigned int MaxNEPaths(Point point1, Point point2)
{
	return 0;
}

unsigned int MaxNEPathsBad(Point point1, Point point2)
{
	return 0;
}

void PrintPrimeNumbers(unsigned int number)
{
}

void PrintSievePrimeNumbers(unsigned int number)
{
}

void HanoiMove(int size, int*& src, int*& dst, int*& tmp)
{
}

void PrintChessBoard(bool ChessBoard[][8])
{
}

bool** PlaceQueens(bool ChessBoard[][8])
{
	return nullptr;
}

float GetClockHandlesAngle(unsigned int hours, unsigned int minutes)
{
	return 0.0f;
}

unsigned FindChainCuts(unsigned chainLinks)
{
	return 0;
}

int GetModDiv(int base, int power, int mod, int& loopCount)
{
	return 0;
}
