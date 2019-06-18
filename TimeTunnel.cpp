// TimeTunnel.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
You must unlock the door to the time tunnel to get home!

-The locking mechanism consists of 12 locks.
-Each lock contains four stones, each with 5 possible colors.
-You can try a combination of stones to open the lock.
-If the combination is not correct, the mechanism gives feedback:
	-Number of stones incorrectly placed (0)
	-Number of stones correctly colored (1)
	-Number of stones correct placed and colored (2)
-You have 10 attempts to solve the lock or you lose
-Open all 12 locks to unlock the door.

Main Menu Options:
-h lists commands and instructions
-n starts a new puzzle
-e exits the game

Puzzle Input:
Type a string of four letters to guess the lock combination.
Letter index is the stone index
r = red
o = orange
y = yellow
g = green
b = blue
Example: yrgb

*/

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <sstream>
#include "CPuzzle.h"

void play(CPuzzle* puzzle) 
{

}

int main()
{
	int lockerror = 0;
	int stonescorrect = 0;
	std::string input = "";
	srand(time(NULL));								// Seed the random number generator
	std::cout << "Welcome to Time Tunnel!\nMain Menu Options:\n-h lists commands and instructions\n-n starts a new puzzle\n-e exits the game\n";
	while(true) 
	{
		std::getline(std::cin, input);
		if (input == "-h")
		{
			std::cout << "Main Menu Options:\n-h lists commands and instructions\n-n starts a new puzzle\n-e exits the game\n\n";
			std::cout << "You must unlock the door to the time tunnel to get home!\n-The locking mechanism consists of 12 locks.\n\n";
			std::cout << "Puzzle Input:\nType a string of four letters to guess the color and position of four stones,\nr = red\no = orange\ny = yellow\ng = green\nb = blue\n";
		}
		else if (input == "-n") 
		{
			CPuzzle* puzzle = new CPuzzle;					// Create an instance of the puzzle
			std::cout << "Started new puzzle.\n";
			std::cout << "Puzzle Input:\nType a string of four letters to guess the color and position of four stones,\nr = red\no = orange\ny = yellow\ng = green\nb = blue\n";
			while(true)										// Play the game
			{
				std::getline(std::cin, input);
				if (input == "-h") 
				{
					std::cout << "Puzzle Input:\nType a string of four letters to guess the color and position of four stones,\nr = red\no = orange\ny = yellow\ng = green\nb = blue\n";
					std::cout << "-h lists commands and instructions\n\n-e exits to the main menu\n";
				}
				else if (input == "-e") 
				{
					std::cout << "Ending puzzle and exiting to main menu..\n";
					delete puzzle;
					break;
				}
				else 
				{
					CLock* currentlock = new CLock; // Container for user input guess
					std::vector<int> response(numstonesperlock);
					if (input.length() == numstonesperlock)		// Input buffer is correct size, check if its valid
					{
						for (int i = 0; i < numstonesperlock; i++) // Iterate through characters, exit if an invalid character is found
						{
							switch (input[i])
							{
							case 'r': currentlock->stones[i].Color = red; break;
							case 'o': currentlock->stones[i].Color = orange; break;
							case 'y': currentlock->stones[i].Color = yellow; break;
							case 'g': currentlock->stones[i].Color = green; break;
							case 'b': currentlock->stones[i].Color = blue; break;
							default: std::cout << "Invalid stone colors. Type -h for help.\n"; lockerror = 1;
							}
							if (lockerror) break;
						}
						if (lockerror) // Exit if there was an error
						{
							delete currentlock;
							lockerror = 0; // reset
							break;
						}
						if (puzzle->guess(currentlock)) // Send the guess combination to the puzzle, check if game is over at the return
						{
							break;
						}
					}
				}
			}
		}
		else if (input == "-e") 
		{
			std::cout << "Exiting...\n";
			return 0;
		}
		else 
		{
			std::cout << "That input was not a valid command. Type -h if you need help.\n";
		}
	}
	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu