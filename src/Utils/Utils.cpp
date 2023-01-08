#include "Utils.h"
#include <cmath>
#include <limits>


bool IsEqual(float x, float y, int precision)
{
	// Sacle the machine epsilon to the magnitude of the given values and multiply by the precision
	return fabs(x - y) <= std::numeric_limits<float>::epsilon() * fabs(x + y) * precision 
		|| fabs(x - y) < std::numeric_limits<float>::min(); // Result is subnormal
}

bool IsGreaterOrEqual(float x, float y)
{
	return x > y || IsEqual(x, y);
}

bool IsLesserOrEqual(float x, float y)
{
	return x < y || IsEqual(x, y);
}
