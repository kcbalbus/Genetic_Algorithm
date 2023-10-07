#include "RandomGenerator.h"


RandomGenerator::RandomGenerator()
{
	
}


float RandomGenerator::generateFloat(float lowerBound, float upperBound)
{
	mt19937 generator(randomDevice());
	uniform_real_distribution<float> distribution(lowerBound, upperBound);
	return distribution(generator);
}


int RandomGenerator::generateInt(int lowerBound, int upperBound)
{
	mt19937 generator(randomDevice());
	uniform_int_distribution<> distribution(lowerBound, upperBound);
	return distribution(generator);
}