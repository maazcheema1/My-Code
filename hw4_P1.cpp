/* PIC 10A, Homework 4 P1
Purpose: Use Monte Carlo method to compute area of the blue ellipse
Author: Maaz Cheema
Date: 2/11/19
*/

#include <iostream>
#include <cmath>
#include <cstdlib>  //pseduorandom number generator
#include <iomanip>	//manipulators
#include <ctime>
using namespace std;
int main()
{
	double exact_area = 2.22144146907918, sqaure_area = 4.0, estimated_area, error, x, y, fmin=-1, fmax=1; //fmin and fmax are the boundaries of the square
	int i, N = 10, count=0;
	srand(time(0)); //generates pseudorandom numbers
;	for (; N <= 1000000; N *= 10) //nested for loop
	{
		count = 0;
		for (i = 0; i < N; i++)		//first chunk of code before the first semicolon is variable initialization. Next chunk is boundary of variables and the last chunk tells the program how to update variables
		{
			x = (fmax-fmin) * (double)rand() / RAND_MAX + fmin; //(x, y) is a random point inside the square. Code is based off rand()/RAND_MAX*(b-a)+a, which gives a random floating point between a and b
			y = (fmax-fmin) * (double)rand() / RAND_MAX + fmin; //want to generate 2 double numbers between -1 and 1. After these lines we generate random coordinates for the dart
			if (x*x + 2 * y*y <= 1)		
				count++; 
		}
		estimated_area = double (count) / N * sqaure_area;
		error = fabs(estimated_area - exact_area); //check portion of darts in ellipse
		cout << fixed << setprecision(5) << "# darts: " << left << setw(7) << N << "   " << "estimated area = " << estimated_area << "  " << "error = " << error << endl; 			
	}	//random generator gives different outcomes what matters is if the error is decreasing. Whole point is more darts you throw the closer the estimate gets to the exact area
	
	return 0;

}