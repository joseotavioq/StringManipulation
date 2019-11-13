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

int PrintPrimeNumbers(unsigned int number)
{
	int count = 0;

	for (size_t i = 2; i <= number; i++)
	{
		bool isPrime = true;

		for (size_t j = 2; j < i; j++)
		{
			if (i % j == 0)
			{
				isPrime = false;
				break;
			}
		}

		if (isPrime)
			count++;
	}

	return count;
}

int PrintSievePrimeNumbers(unsigned int number)
{
	bool numbers[300];
	mymemset(numbers, true, number);

	for (int p = 2; p * p <= number; p++)
	{
		if (numbers[p] == true)
		{
			for (int i = p * p; i <= number; i += p)
			{
				numbers[i] = false;
			}
		}
	}

	int count = 0;
	for (size_t i = 2; i <= number; i++)
	{
		if (numbers[i])
			count++;
	}

	return count;
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
	if (hours >= 12 && hours <= 23)
		hours -= 12;
	
	float totalMinutes = (hours * 60) + minutes;
	float angleForMinutes = 6 * minutes;

	float angle = (0.5 * totalMinutes) - angleForMinutes;

	return angle;
}

unsigned FindChainCuts(unsigned chainLinks)
{
	return 0;
}

int GetModDiv(int base, int power, int mod, int& loopCount)
{
	return 0;
}