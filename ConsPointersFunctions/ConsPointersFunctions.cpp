// ConsPointersFunctions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "FunctionExercises.h"
#include "PointersExercises.h"

#include "ConsPointersFunctions.h"

using namespace std;



int main()
{
    std::cout << "Hello World!\n";

    

    int a = 3, b = 12;
    cout << "Before the Exchange of a and b: a is now " << a << " and b is now " << b << endl;
    ExchangeValues(a, b);
    cout << "After the Exchange of a and b: a is now " << a << " and b is now " << b << endl;
    cout << endl;

    int nums[] = {10, 20, 30, 40, 50, 60, 70};
    int lenOfNums =
        FindArrayLenInts(&nums[0], &nums[6]);

    cout << "The number of elements in the nums array is " << lenOfNums << endl;

    int* pa = &a;
    int* pb = &b;

    SwapPtrs(pa, pb);
    cout << "After the Swap of a and b: a is now " << *pa << " and b is now " << *pb << endl;
    cout << endl;

    // NOTE: MAX_ROOMS and MAX_GUESTS are defined as a const int in PointersExercises.h.
    // 1. Initialize a int array of MAX_ROOMS, rooms, which represents the available rooms in a hotel.
    // 2. Initialize an int* array of MAX_GUESTS, guests, which represents the guests that may check-in and eventually out of the hotel.

    // With the hotel a 0 means vacant, and 1 means occupied.
    // There are always fewer rooms then potential guests so sometimes a guest may have to wait for a vacancy before they can "check in".
    // The room is vacant when the value is true, and occupied when it is false.
    // At the start of this function all of the elements of the rooms array are vacant (all true) and
    // all of the elements of the guests array are assigned nullptr.
    
    // When a guest arrives the function will look for an available room and if there is one then 
    // a) The value of the room is changed to 1 (occupied) and 
    // b) the address of the room is assigned to the corresponding element in the guests array.
    
    // EXAMPLE:
    // If the 2nd element of rooms (rooms[1]) is available then change it's value to false and
    // initialize the guests[i] value to the address of rooms[i].
    // guests[i] = &rooms[i];

    // Three methods are needed for this simulation
    
    // 1. Determine if there is any vacancy (at least one room is unoccupied)
    // bool HasVacancy(int rooms[MAX_ROOMS]) which returns true if there is at least one vacant room.
    
    // 2. Assign the first available room to the current guest - this is the element in the guests array 
    // at currentGuestPosition.
    // Remember that you are giving the guest the address of the room, not the occupancy value of the room.
    // 
    // void AssignRoomToGuest( int rooms[MAX_ROOMS], int guests[MAX_GUESTS], int currentGuestPosition)
    int hotelRooms[MAX_ROOMS] = { 0 };
    int* availableRoom = GetKeyOfFindFirstAvailableHotelRoom(hotelRooms);
    cout << availableRoom;
    

}


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
    a = 5, b = 3;
    int pow = PowerOf(a, b);
    cout << a << " to the power of " << b << " = " << pow << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
