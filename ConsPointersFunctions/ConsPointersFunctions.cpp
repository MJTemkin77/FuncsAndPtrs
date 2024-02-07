// ConsPointersFunctions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "FunctionExercises.h"
#include "PointersExercises.h"

#include "ConsPointersFunctions.h"

using namespace std;


/// <summary>
/// DO NOT CHANGE any of the code in this file.
/// This file will call the functions found in FunctionsExercises.cpp and PointersExercises.cpp that 
/// you will complete as part of this assignment.
/// </summary>
/// <returns>1 or 0 which have no meaning at this point.</returns>
int main()
{

	cout << "Functions Exercises" << endl;
	cout << "==============================" << endl;
	FunctionExercises();
	cout << endl;
	cout << "Hit 'y' to continue:";
	char ans;
	cin >> ans;

	if (ans != 'y')
		return 0;

	cout << "Pointers Exchange and Arithmetic Exercises" << endl;
	cout << "==============================" << endl;
	PointersExchangeArithmeticExercises();
	return 1;


}

/// <summary>
/// DO NOT CHANGE ANY CODE in this function
/// </summary>
void FunctionExercises()
{
	// Function exercises

	//1. Return sum of parameters
	int a = 3, b = 12;
	int sum = Sum(a, b);
	cout << "Sum of " << a << " and " << b << " = " << sum << endl;
	cout << endl;

	//2. Swap reference parameters
	cout << "Before the Swap of a and b: a is now " << a << " and b is now " << b << endl;
	Swap(a, b);
	cout << "After the Swap of a and b: a is now " << a << " and b is now " << b << endl;
	cout << endl;

	//3. Overloaded examples
	double prices[] = { 7.5, 10.50, 21, 3.25, 51 };
	cout << "The total of ";
	int len = sizeof(prices) / sizeof(double);
	for (size_t i = 0; i < len; i++)
	{
		cout << prices[i] << ",";
	}
	cout << " is: " << SumItems(prices, len) << endl;
	cout << endl;

	double discount = .1;
	double threshold = 25;
	cout << "The total of ";
	for (size_t i = 0; i < len; i++)
	{
		cout << prices[i] << ",";
	}
	cout << " with a discount of " << discount <<
		" with credit is: " << SumItems(prices, len, discount) << endl << " and ";


	cout << " is double the discount: " << SumItems(prices, len, discount, true) << " when paid by cash or debit " << endl;
	cout << endl;

	//4. Recursive - PowerOf
	a = 2, b = 3;
	int pow = PowerOf(a, b);
	cout << a << " to the power of " << b << " = " << pow << endl;
}

/// <summary>
/// DO NOT CHANGE ANY CODE in this function
/// </summary>
void PointersExchangeArithmeticExercises()
{
	int a = 3, b = 12;
	cout << "Comparing the Swap defined in Functions with Swap Ptrs" << endl;
	cout << "Using Swap: (Before) a is now " << a << " and b is now " << b << endl;
	Swap(a, b);
	cout << "Using Swap: (After)  a is now " << a << " and b is now " << b << endl;
	cout << endl;

	// Reset the values of a and b
	a = 3, b = 12;

	// Assign the addresses of a and p to pointer to int variables.
	int* pa = &a;
	int* pb = &b;

	cout << "Using SwapPtrs: (Before) pointer to a is now " << *pa << " and pointer to b is now " << *pb << endl;
	SwapPtrs(pa, pb);
	cout << "Using SwapPtrs: (After) pointer to a is now " << *pa << " and pointer to b is now " << *pb << endl;
	cout << endl;


	int nums[] = { 10, 20, 30, 40, 50, 60, 70 };
	int elementsBetweenThePointers =
		DistanceBetweenPointers(&nums[2], &nums[5]);

	DisplayArray(nums);
	cout << "The number of elements between " << nums[2] << " and " << nums[5] << " is: " << elementsBetweenThePointers << endl;

}


/// <summary>
/// Display the list of numbers as a comma-delimited string.
/// </summary>
/// <param name="nums">The static array for this exercise</param>
void DisplayArray(int  nums[7])
{
	unsigned len = sizeof(nums) / sizeof(int);
	for (unsigned i = 0; i < len; i++)
	{
		if (i < len - 1)
			cout << nums[i] << ",";
		else
			cout << nums[i];
	}
	cout << endl;
}







