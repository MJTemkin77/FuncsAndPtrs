#pragma once
/*
   1. Return int with copy parameters
   2. Swap reference parameters
       
   3. Overloaded example
       double Sum(array of double, discount, limit)
       double Sum(array of double)

       // Optional parameters
       double Sum(array of double, discount, limit=0)

   4. Recursive
       int PowerOf(int base, int exp)

   */

//1. Return sum of parameters
int Sum(int a, int b);

//2. Swap reference parameters
void Swap(int& a, int& b);

// 3. Overloaded examples
// Return the sum of the array
double SumItems(double prices[], int len);
// Return the sum of the array after applying a discount, 
// with a double discount when using cash.
// Example:a 10 percent discount when the total purchase is over 50.
double SumItems(double prices[], int len, double discount, bool isCash = false);
// 4. Recursive
// Return the first parameter to the power of the second parameter.
int PowerOf(int, int);

