// ConsPointersFunctions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "FunctionExercises.h"
#include "PointersExercises.h"

#include "ConsPointersFunctions.h"

using namespace std;



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
    cout << endl;
    cout << "Hit 'y' to continue:";
    ans;
    cin >> ans;

    if (ans != 'y')
        return 0;


    cout << "Pointers Hotel Simulation Exercies" << endl;
    cout << "==============================" << endl;
    PointersHotelSimulation();
    cout << endl;

    cout << "END";
    cout << endl;

}

void PointersExchangeArithmeticExercises()
{
    int a = 3, b = 12;
    cout << "Before the Exchange of a and b: a is now " << a << " and b is now " << b << endl;
    ExchangeValues(a, b);
    cout << "After the Exchange of a and b: a is now " << a << " and b is now " << b << endl;
    cout << endl;

    int nums[] = { 10, 20, 30, 40, 50, 60, 70 };
    int lenOfNums =
        FindArrayLenInts(&nums[0], &nums[6]);

    cout << "The number of elements in the nums array is " << lenOfNums << endl;

    int* pa = &a;
    int* pb = &b;

    SwapPtrs(pa, pb);
    cout << "After the Swap of a and b: a is now " << *pa << " and b is now " << *pb << endl;
    cout << endl;
}

void PointersHotelSimulation()
{
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
    // Change the value of the room to occupied (1) and 
    // set the corresponding element in the guest array to the address of the room.
    // 
    // bool AssignRoomToGuest( int rooms[MAX_ROOMS], int guests[MAX_GUESTS], int currentGuestPosition)

    // 3. When the guest leaves the hotel then reset the room that they occupied to vacant (0) and
    // change the value of the guest element to nullptr.

    // 4. Display their room number by using pointer arithmetic to subtract the baseAddressOfTheHotel
    // from the guest[guestNo] value which is the address of their room.
    // If this is hard to understand think of the classroom building for IAM. It is 916.
    // If the starting address of the block is 900 then we would print address 16 of the 900 block.
    // Address (916) - baseAddress (900) = 16
    // int GetRoomNumber(int* baseAddressOfTheHotel, int* guestRoom);

    // All hotel rooms are initialized to zero (vacant)
    int hotelRooms[MAX_ROOMS] = { VACANT };


    // USE nullptr rather than NULL as nullptr is a C++ keyword, and NULL is a macro.
    // https://stackoverflow.com/questions/1282295/what-is-the-nullptr-keyword-and-why-is-it-better-than-null
    // All guests are initialzed to no room assignments.
    int* guests[MAX_GUESTS] = { nullptr };

    
    int positionOfLastGuestAssigned = AssignGuests(hotelRooms, guests);
    std::cout << "There are " << MAX_GUESTS << " persons waiting to get a room from the " << MAX_ROOMS << " available rooms." << endl;
    std::cout << "ROOM ASSIGNMENTS to the first " << (MAX_GUESTS < MAX_ROOMS ? MAX_GUESTS : MAX_ROOMS) << " guests." << endl;
    std::cout << "=======================================" << endl;
    ShowRoomStatus(hotelRooms);

    cout << "Hit 'y' to continue:";
    char ans;
    cin >> ans;


    std::cout << endl;
    std::cout << "GUEST CHECKOUT" << endl;
    std::cout << "=======================================" << endl;

    // Release some of the rooms - The guests in the following zero-based rooms will check out
    int checkOuts[] = { 0, 1, 3, 4, 7 };
    LeaveRooms(hotelRooms, guests, checkOuts, sizeof(checkOuts) / sizeof(int));

    std::cout << endl;
    std::cout << "GUESTS who have left" << endl;
    std::cout << "=======================================" << endl;

    for (int guestNo = 0; guestNo < MAX_ROOMS; guestNo++)
    {
        if (guests[guestNo] == nullptr)
            std::cout << "Guest in Room # " << guestNo + 1 << " has checked out" << endl;
    }
    cout << "Hit 'y' to continue:";
    cin >> ans;

    ShowRoomStatus(hotelRooms);

    std::cout << "MORE ROOM ASSIGNMENTS to those on the Waiting List" << endl;
    std::cout << "=======================================" << endl;
    int nextGuestInLine = positionOfLastGuestAssigned + 1;
    positionOfLastGuestAssigned = AssignGuests(hotelRooms, guests, nextGuestInLine);
    
    ShowRoomStatus(hotelRooms);

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
