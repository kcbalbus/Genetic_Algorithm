#pragma once
#include <random>
#include <iostream>
using namespace std;

class RandomGenerator {
private:
    random_device randomDevice;

public:
    RandomGenerator();
    float generateFloat(float lowerBound, float upperBound);
    int generateInt(int lowerBound, int upperBound);
};