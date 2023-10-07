#pragma once
#include <iostream>
#include <vector>
#include "CKnapsackProblem.h"
#include "RandomGenerator.h"
using namespace std;

class CIndividual {
private:
    vector<int> viGenotype;
    CKnapsackProblem ckpProblem;
    RandomGenerator randomGenerator;

    vector<int> generateGenotype(int size);


public:
    CIndividual(CKnapsackProblem problem);
    CIndividual(CKnapsackProblem problem, vector<int> genotype);
    CIndividual(const CIndividual&);
    ~CIndividual();

    int calculateValue();
    int calculateSize();
    void mutate(float mutProb);
    vector<CIndividual*> cross(CIndividual* other, float crossProb);
    void printSolution();
    
};
