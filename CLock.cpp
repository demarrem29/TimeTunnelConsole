#include "CLock.h"
CLock::CLock() 
{
	stones.reserve(numstonesperlock);
	for (int i = 0; i < numstonesperlock; i++)
	{
		stones.push_back(CStone());
	}
}
