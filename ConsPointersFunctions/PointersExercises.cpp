#include "PointersExercises.h"
#include <iostream>



void SwapPtrs(int* &a, int* &b)
{
	int* temp = a; // Address of a
	a = b;
	b = temp;
}

/// <summary>
/// Find the length of an array based on the 
/// address of the first and last elements.
/// </summary>
/// <param name="nums"></param>
/// <returns></returns>
int DistanceBetweenPointers(int* pa, int* pb)
{
	int distanceBetweenPtrs = (int)( pb - pa + 1);
	return distanceBetweenPtrs;
}


