/* PIC 10A 1A, Homework 1
Purpose: final score based on dual grading system
Author: Maaz Cheema
Date: 1/25/2019
*/
#include <iostream> //allows user to use cin and cout
#include <string> //introduces string variable
using namespace std; //finds cout

int main()
{
	double f, m, hw, sum = 0, avghw = 0, lowesthw = 100, schemeA, schemeB, max;		//must have descriptive variable names. f refers to the final exam grade and m refers to the midterm grade. 
	int N;
	string grade;
	cout << "Please enter the midterm exam score (0-100): \n"; //prints output (expression) to screen
	cin >> m; //asks user to input in the midterm score
	cout << "Please enter the final exam score (0-100): \n";
	cin >> f; //asks user to input in the final exam score
	cout << "Please enter the number of homework assignments (3-7): \n"; //example of loop is when you put in 4 for N it won't run homework 5-7 because they're false. Must be a for loop. Don't make an infinity loop. Compiler won't know.
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cout << "Please enter the homework " << i + 1 << " score (0-100):" << endl; //assume user always put in number from 0-100
		cin >> hw;
		if (lowesthw>hw) //if lowest hw is greater than any other hw value, set it equal to the lowest hw value and then subtract the two values from each other at the end with the sum of the hws so the lowest hw value is dropped. 
		{ 
			lowesthw = hw;
		}
		sum += hw; //+= operation is why sum needs to = 0. Same for lowesthw below. 
		avghw = (sum - lowesthw) / (N - 1);
	}
	schemeA = m * .35 + f * .4 + avghw * .25;
	schemeB = f * .7 + avghw * .3;
	if (schemeA >= schemeB) //max is the greater of schemeA and schemeB. 
	{
		max = schemeA;
	}
	else
	{
		max = schemeB;
	}
	if (max >= 90.) 	// Based on this: 90 <= A <= 100, 80 <= B < 90, 70 <= C < 80, s60 <= D < 70, 0 <= F < 60. (90 <= grade <= 100) won't work unless you use &&
		grade = "A";
	else if (max >= 80.)
		grade = "B";
	else if (max >= 70.)
		grade = "C";
	else if (max >= 60.)
		grade = "D";
	else				//else lines aren't supposed to have (condition)
		grade = "F";
	cout << "Your final score based on Scheme A is " << schemeA << endl;
	cout << "Your final score based on Scheme B is " << schemeB << endl;
	cout << "Your final score is " << max << endl;
	cout << "Your course grade is " << grade << endl;		
	return 0;
}


