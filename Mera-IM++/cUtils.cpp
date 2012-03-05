#pragma once

#include "cUtils.h"

cUtils::cUtils()
{
}
cUtils::~cUtils()
{
}

int cUtils::IntLenInChar(int Value)
{
	int c = 0;
	while (Value > 0)
	{
		Value = Value/10;
		c++;
	}
	return c;
}