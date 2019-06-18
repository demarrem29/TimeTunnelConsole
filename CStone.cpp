#include "CStone.h"
CStone::CStone() :
	Color(red)
{
	switch (rand() % numstonesperlock + 1) // Pick a random color value while constructing the lock
	{
	case 1: Color = red; break;
	case 2: Color = orange; break;
	case 3: Color = yellow; break;
	case 4: Color = green; break;
	case 5: Color = blue; break;
	default: Color = red;
	}
}