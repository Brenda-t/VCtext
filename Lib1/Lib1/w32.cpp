#include "stdafx.h"
#include "w32.h"


int factorial(int n)
{
	int s = 1;
	for (int i = 1; i < n; i++)
	{
		s = s*i;
	}
	return s;
}
