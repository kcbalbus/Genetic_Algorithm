#pragma once
#include <string>
#include <iostream>
using namespace std;

class ValueChecker{
private:

public:
    ValueChecker();
    void checkFloat(float value, float lowerBound, float upperBound, string message);
    void checkInt(int value, int lowerBound, string message);
};
