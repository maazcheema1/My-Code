/* PIC 10A, Homework 4 P2
Purpose: Random walk robot
Author: Maaz Cheema
Date: 2/12/18
*/
#include <iostream>
#include <cstdlib> //pseudorandom number generator
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

int main()
{
	int x=0, y=0; //initial position
	string direction;
	srand(time(0));
	do //using a do-while loop because the loop needs to run at least once and it isn't running a fixed number of times
	{
		int decide_direction = rand() % 4; //Generates pseudo random integer between 0 and 4. No + in the line because it would be + 0
		if (decide_direction == 1)
			direction = "Left", x -= 1, y = y; //decreases x to -5 
		else if (decide_direction == 2)
			direction = "Right", x += 1, y = y; //increases x to 5
		else if (decide_direction == 3)
			direction = "Up", x = x, y += 1; //increases y to 5
		else
			direction = "Down", x = x, y -= 1; //decreases y to -5
		cout << left << setw(5) << direction << "   " << "(" << x << ", " << y << ")" << endl;
		if (x == -5 || x == 5 || y == -5 || y == 5)
		{
			cout << "Hit the boundary!" << endl;
			break;
		}

		else if (x == 0 && y == 0) //return to origin
		{
			cout << "Back to the origin!" << endl;
			break;
		}

	} 
	
	while (true); 
		
	return 0;
}