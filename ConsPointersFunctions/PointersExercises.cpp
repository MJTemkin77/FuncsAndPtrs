#include "PointersExercises.h"

void ExchangeValues(int &a, int &b)
{
	int* pa = &a;
	int* pb = &b;
	int temp = *pa;

	a = *pb;
	pa = &temp;
	b = *pa;

}

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
int FindArrayLenInts(int* pa, int* pb)
{
	int distanceBetweenPtrs = pb - pa + 1;
	return distanceBetweenPtrs;
}


int* GetKeyOfFindFirstAvailableHotelRoom(int rooms[MAX_ROOMS])
{
	int* availableRoom = nullptr;
	bool fnd = false;
	for (size_t i = 0; i < MAX_ROOMS && !fnd; i++)
	{
		if (rooms[i] == 0)
		{
			fnd = true;
			availableRoom = rooms + i;
			rooms[i] == -1;
		}
	}

	return availableRoom;
}

