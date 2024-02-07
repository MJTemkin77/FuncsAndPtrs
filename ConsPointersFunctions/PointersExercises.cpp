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
	int distanceBetweenPtrs = (int)( pb - pa + 1);
	return distanceBetweenPtrs;
}


bool HasVacancy(int rooms[MAX_ROOMS])
{
	bool findVacantRoom = false;
	for (int i = 0; i < MAX_GUESTS && !findVacantRoom; i++)
	{
		findVacantRoom = rooms[i] == VACANT;
	}
	return findVacantRoom;
}

int GetRoomNumber(int* baseAddressOfTheHotel, int* guestRoom)
{
	return (int) (guestRoom - baseAddressOfTheHotel);
}

int* AssignRoomToGuest(int rooms[MAX_ROOMS])
{
	int* roomToAssign = nullptr;

	
	for (int i = 0; i < MAX_ROOMS && roomToAssign == nullptr; i++)
	{
		if (rooms[i] == VACANT)
		{
			roomToAssign = rooms + i;
			rooms[i] = OCCUPIED;
		}
	}

	return roomToAssign;
}

void LeaveRoom(int rooms[MAX_ROOMS], int position)
{
	rooms[position] = VACANT;
}

