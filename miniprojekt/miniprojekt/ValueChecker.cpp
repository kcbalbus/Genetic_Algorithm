#include "ValueChecker.h"

ValueChecker::ValueChecker()
{
}

void ValueChecker::checkFloat(float value, float lowerBound, float upperBound, string message)
{
	if (value<lowerBound || value>upperBound)
	{
		throw message + " must be beetween " + to_string(lowerBound) + " and " + to_string(upperBound) + "!";
	}
}

void ValueChecker::checkInt(int value, int lowerBound, string message)
{
	if (value < lowerBound)
	{
		throw message + " can not be less than " + to_string(lowerBound) + "!";
	}
}
