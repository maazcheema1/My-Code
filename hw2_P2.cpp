/*
PIC 10A 1A, Hw 2
Purpose: product of digits
Author: Maaz Cheema
UID: 905081807
Date: 1/21/2019
*/

#include <iostream> //use cout and cin
using namespace std; //finds cout
int main()
{
	int x, digit1, digit2, digit3, result;
	cout << "Input an integer between 100 and 999: \n"; // asks user for input. Assume user always puts in number within the range. 
	cin >> x; //variable can't be int because that's a C++ keyword.
	digit1 = x % 10;
	x = x / 10;
	digit2 = x % 10;
	x = x / 10;
	digit3 = x % 10;
	result = digit1 * digit2*digit3;
	cout << "The product of digits is " << result << "." << endl; //Remainder gives you this because if you multiply 3rd digit by 1, 2nd digit by 10, and 1st digit by 100, then add them up, you will get the original 3 digit integer. Need to think about it backwards!
	return 0;
}							 