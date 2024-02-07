#include "PointersExercises.h"
#include <iostream>

// TODO 5: Do a swap with pointers

/// <summary>
/// Using the swap with references as a model,
/// swap the values of the pointers.
/// The syntax int* &a for example means that 
/// the parameter is a pointer passed by reference.
/// This means that the function can change the value of the pointer.
/// IE it means that the function can change the content of the pointer with another address.
/// HINT: Your temp variable is also a int* which takes on the address of a or b whichever
/// is going to be overwritten in the second line.
/// </summary>
/// <param name="a"></param>
/// <param name="b"></param>
void SwapPtrs(int* &a, int* &b)
{
	int* temp = a; // Address of a
	a = b;
	b = temp;
}

// TODO 6: Find the length between two pointers.

/// <summary>
/// Find the length between two pointers that includes the two positions.
/// Example: if the pointers are coming from an array of 10 elements and
/// pa points at the 2nd element and pb points at the 4th element then the distance is 3
/// because we are including pa and pb. Not excluding them.
/// Assume that pa is lower in the array then pb.
/// pa might be at position 1 and pb would be at a position greater than position 1.
/// You may have to use an explicit cast like
/// int result = (int) your expression goes here.
/// </summary>
/// <param name="nums"></param>
/// <returns></returns>
int DistanceBetweenPointers(int* pa, int* pb)
{
	int distanceBetweenPtrs = (int)( pb - pa + 1);
	return distanceBetweenPtrs;
}


