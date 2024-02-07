#include "FunctionExercises.h"

// TODO 1: Function returns a value has copy by value parameters.

/// <summary>
/// Sum below uses copy by value parameters.
/// You need to return the sum of the two int parameters.
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>
int Sum(int a, int b)
{
	return a + b;
}

// TODO 2: Swap the value of the reference parameters

/// <summary>
/// Swap does NOT return a value. (Notice the void return type)
/// This method needs to exchange the values of the parameters.
/// a takes on the value of b, and b takes on the value of a.
/// To do this the function will need a local variable that has the 
/// value of the first parameter
/// so that the first parameter can be initialized to the second parameter,
/// and then the second parameter can be initialized to the value of the local variables.
/// </summary>
/// <param name="a">First parameter</param>
/// <param name="b">Second parameter</param>

void Swap(int& a, int& b)
{
	int temp = b;
	b = a;
	a = temp;
}

// TODO 3a: Overloaded examples.

/// <summary>
/// To the first function that has a shared name, in this case SumItems,
/// returns a double, but has a unique list of parameters, in terms of types, order, 
/// and quantity of parameters.
/// 
/// This function gets the sum of the prices in the array.
/// </summary>
/// <param name="prices">The array of prices</param>
/// <param name="len">The length of the array. C++ objects on using the sizeof operator on an array of an unspecified size. 
/// For that reason the length (len) of this array is passed as a parameter.
/// </param>
/// <returns>The sum of all the prices</returns>
double SumItems(double prices[], int len)
{
	double sum = 0;
	for (size_t i = 0; i < len; i++)
	{
		sum += prices[i];
	}
	return sum;
}

// TODO 3b: Overloaded examples.


/// <summary>
///Return the sum of the array after applying a discount,
///when the sum is over the optional threshold.
///Example:a 10 percent discount when the total purchase is over 50.
///If the buyer uses cash then double the discount.
///NOTE: See that in the header file, FunctionExercises.h, isCash has a default value of false.
/// </summary>
/// </summary>
/// <param name="prices">The array of prices</param>
/// <param name="len">The length of the array. C++ objects on using the sizeof operator on an array of an unspecified size. 
/// For that reason the length (len) of this array is passed as a parameter.
/// </param>
/// <param name="discount">What is the discount as double. Examples: 10% is .1, 5% is .05. The parameter is passed as .1, not as 10%</param>
/// <param name="isCash">optional parameter which defaults to false</param>
/// <returns></returns>
double SumItems(double prices[], int len, double discount, bool isCash)
{
	double sum = 0;
	for (size_t i = 0; i < len; i++)
	{
		sum += prices[i];
	}
	if (isCash)
	{
		sum *= (1 - 2 * discount);
	}
	else
	{
		sum *= (1 - discount);
	}
	return sum;
	
}

// TODO 4: Recursive function.

// 4. Recursive

/// <summary>
/// Return the first parameter to the power of the second parameter.
/// NOTE: Remember that the stopping point for exponents is 1.
/// 10^2 = 100, 10^1 = 10, 10^0 = 1 
/// We are not interested in an exponent of zero.
/// We know that the base to the exponent of 1 equals the base. IE 10^1 = 10
/// 
/// Remember that each time the PowerOf method is called recursively the value that 
/// will be compared must be one less so that it reach the condition where the exponent is 1 and the _base is returned.
/// IE there must be a way out of the calling cycle.
/// 
/// </summary>
/// <param name="_base">In the above examples 10 is the base</param>
/// <param name="exponent">In the above examples the number after the ^ in 10^2, 2 is the exponent of 10</param>
/// <returns></returns>
int PowerOf(int _base, int exponent)
{
	if (exponent == 1)
		return _base;
	else
	{
		return _base * PowerOf(_base, exponent - 1);
	}
	
}

