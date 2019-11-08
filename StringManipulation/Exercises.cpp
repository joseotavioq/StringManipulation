#include "Exercises.h"
#include "crt.h"
#include <stdlib.h>

char* GetWrittenAmount(double amount)
{
	char* tmp = new char[1024];

	double onlyDecimals = amount - (int)amount;
	amount = amount - onlyDecimals;

	if (amount == 0 && onlyDecimals > 0)
		amount = onlyDecimals;

	//send all numbers to right
	int countOfDigitsBeforePeriod = 0;
	while (amount >= 1)
	{
		amount /= 10;
		countOfDigitsBeforePeriod++;
	}

	bool hasTyped = false;
	while (amount >= 0 && countOfDigitsBeforePeriod >= -1)
	{
		amount *= 10;
		int amountInt = (int)amount;

		if (amountInt > 0)
		{
			const char* nameOfNumber = "";
			const char* typeOfNumber = "";

			if (countOfDigitsBeforePeriod == 4
				|| countOfDigitsBeforePeriod == 3
				|| countOfDigitsBeforePeriod == 1
				|| countOfDigitsBeforePeriod == -1)
				nameOfNumber = ConvertNumberToText(amountInt);
			else if (countOfDigitsBeforePeriod == 2 || countOfDigitsBeforePeriod == 0)
			{
				if (amountInt == 1)
				{
					amount *= 10;
					amountInt = (int)amount;
					countOfDigitsBeforePeriod--;
				}

				if (hasTyped && countOfDigitsBeforePeriod <= 0)
					mystrcat(tmp, " AND");
				nameOfNumber = ConvertTenToText(amountInt);
			}

			if (countOfDigitsBeforePeriod == 4)
				typeOfNumber = " THOUSAND";
			else if (countOfDigitsBeforePeriod == 3)
				typeOfNumber = " HUNDRED";

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

			if (typeOfNumber != "")
				mystrcat(tmp, typeOfNumber);

			if (countOfDigitsBeforePeriod == 1 && onlyDecimals > 0)
				amount = onlyDecimals;
			else
				amount = amount - (int)amount;
		}

		countOfDigitsBeforePeriod--;
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
	if (number == 1 || number == 10)
		return "TEN";
	else if (number == 2)
		return "TWEENTY";
	else if (number == 3)
		return "THIRDY";
	else if (number == 4)
		return "FOURTY";
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
	else if (number == 11)
		return "ELEVEN";
	else if (number == 12)
		return "TWELVE";
	else if (number == 13)
		return "THIRTEEN";
	else if (number == 14)
		return "FOURTEEN";
	else if (number == 15)
		return "FIFTEEN";
	else if (number == 16)
		return "SIXTEEN";
	else if (number == 17)
		return "SEVENTEEN";
	else if (number == 18)
		return "EIGHTEEN";
	else if (number == 19)
		return "NINETEEN";

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