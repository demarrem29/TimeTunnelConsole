#include "CPuzzle.h"

// Puzzle Class Methods

// Constructor
CPuzzle::CPuzzle() :						
	Attempts(0),
	Locks_opened(0),
	gameover(false),
	win(false)
{
	Locks.reserve(numlocks);			// Make sure Locks vector is the correct size
	for (int i = 0; i < numlocks; i++)  // Instantiate locks
	{
		Locks.push_back(CLock());
	}
}

// Check if the user input lock is correct
bool CPuzzle::guess(CLock* inLock)
{
	std::vector<int> retval;		// Create return vector and initialize each value with zero.
	std::vector<int> stonematchguess(numstonesperlock, 0);
	std::vector<int> stonematchactual(numstonesperlock, 0);
	std::vector<int> correctguess(numstonesperlock, 2); // Comparison vector for stonematch
	for (int i = 0; i < numstonesperlock; i++)			// Iterate through guess lock, looking for perfect matches first
	{
		if (inLock->stones[i].Color == Locks[Locks_opened].stones[i].Color) // Exact match found
		{
			retval.push_back(2);
			stonematchguess[i] = 1;
			stonematchactual[i] = 1;
		}
	}
	for (int i = 0; i < numstonesperlock; i++)			// Iterate through guess lock, looking for partial matches
	{
		if (stonematchguess[i] == 0)					// Skip over stones from guess that have already been matched
		{
			for (int j = 0; j < numstonesperlock; j++)
			{
				if (stonematchactual[j] == 0)			// Skip over stones from puzzle that have already been matched
				{
					if (inLock->stones[i].Color == Locks[Locks_opened].stones[j].Color) // Partial match found
					{
						retval.push_back(1);
						stonematchguess[i] = 1;
						stonematchactual[j] = 1;
					}
				}
				
			}
			
		}	
		if (stonematchguess[i] == 0) retval.push_back(0);	// If no matches were found, mark it zero
	}
	for (int i = 0; i < numstonesperlock; i++)
	{
		std::cout << retval[i];
	}
	std::cout << "\n";
	if (retval == correctguess)													// If the guess was perfect
	{
		std::cout << "Correct!\n";													// Move on to next lock
		Locks_opened++;
		Attempts = 0;
		if (Locks_opened >= numlocks)												// If that was the last lock, win instead
		{
			win = true;
			gameover = true;
			std::cout << "You win! You opened all of the locks and the door is open. Returning to main menu.\n";
		}
		else
		{
			std::cout << "There are " << (numlocks - Locks_opened) << " locks remaining.\n";
		}
	}
	else 
	{
		Attempts++;
		if (Attempts >= numattempts) 
		{
			win = false;
			gameover = true;
			Attempts = 0;
			std::cout << "Oh no! You ran out of attempts and the door is now sealed! Game Over!\nReturning to Main Menu.\n";
		}
		std::cout << "Not quite. You have " << (numattempts - Attempts) << " attempts remaining.\n";
		
	}
	return gameover;
}