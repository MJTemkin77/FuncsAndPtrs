#include "FunctionExercises.h"

//1. Return int with copy parameters
int Sum(int a, int b)
{

	return a + b;
}

//2. Swap reference parameters
void Swap(int& a, int& b)
{
	int temp = b;
	b = a;
	a = temp;
}

// 3. Overloaded examples
// Return the sum of the array
double SumItems(double prices[], int len)
{
	double sum = 0;
	for (size_t i = 0; i < len; i++)
	{
		sum += prices[i];
	}
	return sum;
}

// Return the sum of the array after applying a discount, 
// when the sum is over the optional threshold.
// Example:a 10 percent discount when the total purchase is over 50.
// If the buyer uses cash then double the discount.
double SumItems(double prices[], int len, double discount, bool isCash)
{
	double sum = 0;
	for (size_t i = 0; i < len; i++)
	{
		sum += prices[i];
	}
	if (isCash)
	{
		sum *= 1 - discount;
	}
	else
	{
		sum *= 1 - 2 * discount;
	}
	return sum;
	
}
// 4. Recursive
// Return the first parameter to the power of the second parameter.
// NOTE: Remember that the stopping point for exponents is 1.
// 10^2 = 100, 10^1 = 10, 10^0 = 1 
// We are not interested in an exponent of zero.
// We now that the base to the exponent of 1 equals the base.
int PowerOf(int _base, int exponent)
{
	if (exponent == 1)
		return _base;
	else
	{
		return _base * PowerOf(_base, exponent - 1);
	}
	
}

// EXTRA CREDIT RECURSIVE
// Find all the words until the delimiter. EXTRA CREDIT.
const int MAXSENTENCE = 2048;
char* ReadUntilDelimiter(char input[], char delim)
{
	char sentence[2048] = { '\0' };
	return sentence;
}