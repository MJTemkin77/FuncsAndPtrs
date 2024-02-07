#pragma once

// Pointers
   /*
   1. Create two ints, create two pointers to int, pointers exchange the variables that they point to.
   2. Create two ints, create two pointers to int, change the value of the variables using the pointer dereference.
   3. Use the starting and ending address of an array to determine the length of the array
   4. Encrypt an array of chars by changing the address of each element to the address of the previous element, and have the last address become the first.
   5. Decrypt an array of chars by changing the address of each element to the address of the next element, and have the first address become the last.
   */

/// <summary>
/// Create two ints, create two pointers to int, pointers exchange the value of the variables that they point to.
/// Remember that like the other Function Swap the function will still need a temporary variable
/// </summary>
/// <param name="a">A reference to the first parameter</param>
/// <param name="b">A reference to the second parameter</param>
void ExchangeValues(int& a, int& b);

void SwapPtrs(int* &a, int* &b);

// 2. Use the starting and ending address of an array to determine the length of the array
int FindArrayLenInts(int* pa, int* pb);

//3. Encrypt an array of chars by changing the address of each element to the address of the previous element, and have the last address become the first.
//void EncryptChars(char strToEncode[], char encrypted[]);

const int MAX_ROOMS = 10;
const int MAX_GUESTS = 15;
const int OCCUPIED = 1;
const int VACANT = 0;

bool HasVacancy(int rooms[MAX_ROOMS]);
int GetRoomNumber(int* baseAddressOfTheHotel, int* guestRoom);
// 4. Find the first available "room" in the hotel and assign to the guest.


int AssignGuests(int rooms[MAX_ROOMS], int* guests[MAX_GUESTS], int startingPosition = 0);
int* AssignRoomToGuest(int rooms[MAX_ROOMS]);
void LeaveRooms(int rooms[MAX_ROOMS], int* guests[MAX_GUESTS], int checkOuts[], int numOfCheckouts);
void ShowRoomStatus(int  hotelRooms[MAX_ROOMS]);

