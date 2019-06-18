#pragma once
#include "CStone.h"
#include "CLock.h"
#include <vector>
#include <string>
#include <iostream>
/*
-Each lock


*/
#define numlocks 12
#define numattempts 10
#define numstonesperlock 4
class CPuzzle
{
public:
	int Attempts;
	int Locks_opened;
	bool gameover;
	bool win;
	std::vector<class CLock> Locks;			// The array of locks in the puzzle
	bool guess(CLock* inLock);
	CPuzzle();
};




