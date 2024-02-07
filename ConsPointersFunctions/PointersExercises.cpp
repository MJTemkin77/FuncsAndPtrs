#include "PointersExercises.h"
#include <iostream>

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



void LeaveRooms(int rooms[MAX_ROOMS], int* guests[MAX_GUESTS], int checkOuts[], int numOfCheckouts)
{
	for (int i = 0; i < numOfCheckouts; i++)
	{
		int indexOfRoomToLeave = checkOuts[i];
		if (indexOfRoomToLeave < MAX_ROOMS)
		{
			guests[indexOfRoomToLeave] = nullptr;
			rooms[indexOfRoomToLeave] = VACANT;
		}

	}
}

int AssignGuests(int rooms[MAX_ROOMS], int* guests[MAX_GUESTS], int startingPosition)
{
	int positionOfLastGuestAssigned = -1;

	for (int guestNo = startingPosition; guestNo < MAX_GUESTS; guestNo++)
	{
		if (HasVacancy(rooms))
		{
			guests[guestNo] = AssignRoomToGuest(rooms);
			if (guests[guestNo] != nullptr)
			{
				positionOfLastGuestAssigned = guestNo;
			}
		}
	}
	return positionOfLastGuestAssigned;
}

void ShowRoomStatus(int  hotelRooms[MAX_ROOMS])
{
	std::cout << std::endl;
	std::cout << "SHOW ROOM STATUS" << std::endl;
	std::cout << "=======================================" << std::endl;

	for (int roomNo = 0; roomNo < MAX_ROOMS; roomNo++)
	{
		const char* status = hotelRooms[roomNo] == VACANT ? "VACANT" : "OCCUPIED";
		std::cout << "Room # " << roomNo + 1 << " is " << status << std::endl;
	}
}