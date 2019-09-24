/* PIC 10A, Homework 5
Purpose: Create usable menu of options
Author: Maaz Cheema
Date: 2/20/19
*/
#include <iostream>
int lowest, middle, highest;
using namespace std;

void displayMenu() //can't define function inside main function so the voids need to be outside main function.
{
	cout << "================== MENU ==================" << endl; 
	cout << "1. Output the largest" << endl;
	cout << "2. Get the next permutation" << endl;
	cout << "3. Sort in ascending order" << endl;
	cout << "Enter your choice (1 - 3), Q to quit: ";
}
int largest(int a, int b, int c) //can't define function inside main function 
{
	a = a;
	b = b;
	c = c;
	if (a >= b && a >= c) 
	{
		return a;
	}
		
	else if (b >= a && b >= c)
	{
		return b;
	}
	else 
	{
		return c;
		}

}
/*
@param a is the first integer
@param b is the second integer
@param c is the third integer
@returns the largest of the three integers
*/

void mySort(int& a, int& b, int& c) //6 different cases. Uses pass by reference
{
	if (a < b && b < c)
	{
		lowest = a;
		middle = b;
		highest = c; //cba
	}

	else if (b < a && a < c)
	{
		lowest = b;
		middle = a;
		highest = c; //cab
	}
	else if (a < c && c < b)
	{
		lowest = a;
		middle = c;
		highest = b; //bca
	}

	else if (c < a && a < b)
	{
		lowest = c;
		middle = a;
		highest = b; //bac
	}

	else if (c < b && b < a)
	{
		lowest = c;
		middle = b;
		highest = a; //abc
	}
	else
	{
		lowest = b;
		middle = c;
		highest = a; //acb
	}
	cout << "\nAfter sorting: " << lowest << " " << middle << " " << highest << "\n" << endl;
}
/*
@param lowest is the smallest integer
@param middle is the integer that is not the smallest nor the largest
@param highest is the largest integer
@returns the integers in order lowest, middle, and highest
*/
void myPermutation(int& a, int& b, int& c) //pass by reference
{
	a = lowest; //have this here and on lines 108-110 so myPermutation is updated with mySort
	b = middle;
	c = highest;
	int temp1, temp2;
	temp1 = a;
	temp2 = b;
	a = c; // Last digit is first
	b = temp1; // First digit is second
	c = temp2; // Second digit is last
	cout << "\nAfter one permutation: " << a << " " << b << " " << c << "\n" << endl;
	lowest = a; 
	middle = b;
	highest = c;
}
/*
@param temp1 keeps the original value of a for the swap
@param temp2 keeps the original value of b for the swap
*/
int main()  //Code is executed from top to bottom here
{
	int a, b, c, j, largestval; 
	cout << "Enter your three integer numbers: \n";
	cin >> a;
	cin >> b;
	cin >> c;
	lowest = a;
	middle = b;
	highest = c;
	while (true)
	{
		
		displayMenu();
		largestval = largest(a,b,c); //assignment
		cin >> j;
		if (j == 1)
		{
			cout << "\nThe largest number among the three is:  " << largestval << "\n" << endl;
		}
		else if (j == 2)
		{
			myPermutation(a, b, c);
		}
		else if (j == 3)
		{
			mySort(a, b, c);
		}
		else     //assume valid input so user will only input 1, 2, 3, q, and Q
		{
			break;
		}
	}				
			cout << "\n" << "Exit the menu" << endl;

		return 0;
}
/*
@param a is the first intger inputted
@param b is the second integer inputted
@param c is the third integer inputted
@param j is the integer or q key that is inputted, which initiates an if, else if, or else statement
@param largestval is the assignment for the largest integer function, which outputs the largest of the three integers
@returns the end of the menu
*/