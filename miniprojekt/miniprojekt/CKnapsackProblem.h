#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include "ValueChecker.h"
using namespace std;

class CKnapsackProblem {
private:
    int iNumberOfItems;
    int iBackpackCapacity;
    vector<int> vItemSizes;
    vector<int> vItemValues;
    ValueChecker valueCheck;
    void loadFromFile(string fileName);
    void checkVectors(vector<int> sizes, vector<int> values, int numberOfItems);
    void messageAfterLoad();


public:
    CKnapsackProblem();
    CKnapsackProblem(int numberOfItems, int backpackCapacity, vector<int> itemSizes, vector<int> itemValues);
    CKnapsackProblem(string fileName);
    int getNumberOfItems();
    int calculateSolutionValue(vector<int> genotype);
    int calculateSolutionSize(vector<int> genotype);
};

