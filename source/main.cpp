/*
Pointers
(c) 2016
Author: David Erbelding
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

// Include iostream for output during the program.
#include <iostream>
using namespace std;


// Start of main function
int main() 
{
    // Pointers are the real core of C++ programming.
    // At the same time, they are one of the most confusing parts for new programmers.
    // A pointer is a variable that "points" to a specific place in the computers memory.

    /*
        Pointer
        +----+
        |3051|-------+
        +----+       |
                     V
        +----+----+----+----+----+----+----+----+
        |3049|3050|3051|3052|3053|3054|3055|3056| <-- Memory Adresses
        +----+----+----+----+----+----+----+----+
        |????|????|  x |????|????|????|????|????| <-- Memory
        +----+----+----+----+----+----+----+----+
    */

    cout << "Pointers" << endl;
    cout << "Press Enter to Continue" << endl << endl;


    // A pointer is a special variable in C++ that is based on a type.
    {
        int* intPointer;        // Pointers look like this,
        float* floatPointer;    // or this,
        char* charPointer;      // or this etc.

        // The size of all pointers is the same:
        // This depends on the if the program is 32bit or 64bit
        // In 32 bit, the size of a pointer is 4 bytes (32 bits)
        // In 64 bit, the size of a pointer is 8 bytes (64 bits)
        cout << "sizeof(int*): " << sizeof intPointer << endl;
        cout << "sizeof(float*): " << sizeof floatPointer << endl;
        cout << "sizeof(char*): " << sizeof charPointer << endl;
    }
    cin.get();


    // Get a pointer to variable x, and then get the value from the pointer.
    {
        int x = 1;                                  // Storing 5 as an integer.
        cout << "\n[int x = 1;]" << endl;
        cout << "value of x: " << x << endl;

        int* pointerToX = &x;                       // & is called the address-of operator.
        cout << "\n[int* pointerToX = &x;]" << endl;// It takes a variable, and gives you its address.
        cout << "Value stored as pointer to integer: " << pointerToX << endl;

        int y = *pointerToX;                        // * is the dereference operator.
        cout << "\n[int y = *pointerToX;]" << endl; // It takes a memory address and gives you the variable at that location.
        cout << "value stored at y: " << y << endl; // It's the same thing as y = x;
    }
    cin.get();


    // Get a pointer to variable x, and then store a value at that location using the pointer.
    {
        int x = 2;
        cout << "\n[int x = 2;]" << endl;

        int* pointerToX = &x;
        cout << "\n[int* pointerToX = &x;]" << endl;
        cout << "Value stored as pointer to integer: " << pointerToX << endl;

        *pointerToX = 0;                            // Instead of getting the value of x, we write to the value at x.
        cout << "\n[*pointerToX = 0;]" << endl;     // Essentially doing x = 5;
        cout << "value stored at x: " << x << endl;
    }
    cin.get();


    // Here we use both operators at the same time to no effect.
    {
        int x = 3;                                  // Storing 5 as an integer.
        cout << "\n[int x = 3;]" << endl;

        int y = *&x;                                // Get an address, and then immediatley dereference.
        cout << "\n[int y = *&x;]" << endl;
        cout << "value stored at y: " << y << endl;
    }
    cin.get();


    // Here we get two pointers to the same memory.
    // Each pointer can operate on the same variable, but with a different name.
    {
        int x = 4;
        cout << "\n[int x = 4;]" << endl;

        int* firstPointerToX = &x;                          // Get 1st pointer
        int* secondPointerToX = &x;                         // Get 2nd pointer
        cout << "\n[int* firstPointerToX = &x;]" << endl;
        cout << "[int* secondPointerToX = &x;]" << endl;

        *firstPointerToX = 444;                             // Change the value pointed to.
        cout << "\n[*firstPointerToX = 444;]" << endl;      // AKA x = 444;
        cout << "Value pointed to by second pointer: " << *secondPointerToX << endl;
    }
    cin.get();


    // Here we get two pointers to different things, and use one to assign to the other.
    {
        int x = 5;
        int y = 0;
        cout << "\n[int x = 5;]" << endl;
        cout << "[int y = 0;]" << endl;

        int* pointerToX = &x;                               // Get x pointer
        int* pointerToY = &y;                               // Get y pointer
        cout << "\n[int* pointerToX = &x; ]" << endl;
        cout << "[int* pointerToY = &y;  ]" << endl;

        *pointerToY = *pointerToX;                          // Get the value that x points to, and write it to the address y points to.
        cout << "\n[*pointerToY = *pointerToX;]" << endl;   // AKA y = x;
        cout << "Value stored at y: " << y << endl;
    }
    cin.get();


    // It is also possible for pointers to point to nothing at all.
    {
        int* pointer = 0;
        cout << "\npointer address: " << pointer << endl;

        // If you uncomment this line, it will cause an error:
        // int x = *pointer;
        // This is because the pointer is pointing to nothing.

        // The memory adddress 0 is reserved as the null pointer.
        // This makes it easy to compare to make sure you don't try to dereference a null pointer.


        // nullptr is a constant pointer defined in C++ to be a pointer to nothing.
        if (pointer == nullptr)
        {
            cout << "pointer == nullptr" << endl;
        }

        // You may also see NULL, which is the C version.
        // The C++ version is better because it is defined as a pointer type, whereas NULL is literally just 0.
        // This is only here so that you know what it means. You should never use it in C++.
        if (pointer == NULL)
        {
            cout << "pointer == NULL" << endl;
        }
    }
    cin.get();


    

    // Since pointers are also just data, we can also get pointers to pointers.
    // It looks something like this:
    /*

    pointer    pointer
    to         to
    pointer    value      value
    +----+     +----+     +----+
    |    |---->|    |---->|    |
    +----+     +----+     +----+

    */

    {
        int x = 7;
        int* pointerToX = &x;                      // Pointer to x
        int** pointerToPointer = &pointerToX;      // Pointer to pointer to x.

        cout << "\n[int x = 7;]" << endl;
        cout << "[int* pointerToX = &x;]" << endl;
        cout << "[int** pointerToPointer = &pointerToX;]" << endl;

        cout << "&x: " << &x << endl;                               // Print all the ways to get a pointer to x
        cout << "pointerToX: " << pointerToX << endl;
        cout << "*pointerToPointer: " << *pointerToPointer << endl;
        cout << endl;

        cout << "x: " << x << endl;                                 // Print all the ways to get x
        cout << "*pointerToX: " << *pointerToX << endl;
        cout << "**pointerToPointer: " << **pointerToPointer << endl;

        // NOTE: you can't do this:
        // cout << "Get Address twice: " << &&x << endl;
        // why not?
    }
    cin.get();



    cout << "\nEnd of program." << endl;
    cin.get();
    return 0;   // End Program.
}