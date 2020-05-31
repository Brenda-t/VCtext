#include "stdafx.h"
#include "w33.h"
#define PI 3.14

float FAC::convert(float deg)
{
	float s = (float)PI*deg / 180.0;
	return s;
}