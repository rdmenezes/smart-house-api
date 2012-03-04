#include "cUtils.h"
cUtils::cUtils()
{
}
cUtils::~cUtils()
{
}

signed int cUtils::IntLenInChar(signed int Val)
{
	signed int c = 0;
	while (Val > 0)
	{
		Val = Val/10;
		c++;
	}
	return c;
}