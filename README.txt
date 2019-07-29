Documentation Author: Niko Procopi 2019

This tutorial was designed for Visual Studio 2017 / 2019
If the solution does not compile, retarget the solution
to a different version of the Windows SDK. If you do not
have any version of the Windows SDK, it can be installed
from the Visual Studio Installer Tool

Welcome to the Pointer Tutorial!
Prerequesites: Core C++ Intro

Towards the bottom of this Readme, I will show what is 
(in my opinion), the most uesful way to use pointers

A pointer is a location in memory, which tells us exactly where
a chunk of memory is. This chunk of memory can be a char, int,
an array, a structure, absolutely anything. 

============================
How pointers work:
============================

If we have a class or structure like this:

struct Zombie
{
	int health;
	int numberOfLegs;
	int hunger;
}

We can make an object of bob:
	Zombie bob;
"bob" is 12 bytes large, with 3 ints that are each 4 bytes;
We can make a pointer to get the location in memory where bob is:
	Zombie* bobLocation = &bob;
"bobLocation" is 4 bytes large, which tells us where the 12 bytes of "bob" is 

In this C++ tutorial, we will show you why pointers are important,
and where we can use them to make our code better

============================
Why they are helpful:
============================

Take a look at the following code:

void func(int x)
{
	x = 5;
}

int main()
{
	int y = 10;
	func(y);
	cout << y << endl;
}

Many people will expect the program to print "5", but it actually wont,
this program will print "10". In the code written above, the variable "y"
is not actually given to "x" in "func". Instead what is happening is, the
value of "y" is put into a new variable "x", and then "x" is changed to 5, 
without altering "y". Take a look at this new code:

void func(int* x)
{
	*x = 5;
}

int main()
{
	int y = 10;
	func(&y);
	cout << y << endl;
}

&y is a pointer to "y"
int* x, is a pointer to an integer
*x = 5; edits the variable that exists at that pointer

Here, we pass the value, of the pointer, of y, into the value,
of int* x. Therefore, we are not passing the value of "y", we are passing
the location of "y". Inside "func", we use *x to dereference the pointer, which
gives us access to the integer that x points to, which is "y". By doing so, this
allows us to change the variable "y" that is passed to "func", and allow "y" to be 
changed by Func. Finally, the program prints "5".
