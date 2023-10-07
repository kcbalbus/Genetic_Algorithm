#pragma once
#include <iostream>
#include <vector>
#include <string> 
#include "CKnapsackProblem.h"
#include "CIndividual.h"
using namespace std;


class CGeneticAlgorithm {
private:
    int iPopulationSize;
    float fCrossoverProbability;
    float fMutationProbability;
    CKnapsackProblem ckpProblem;
    vector<CIndividual*> ciPopulation;
    int iNumberOfGenerations;
    RandomGenerator randomGenerator;
    ValueChecker valueCheck;

    void initializePopulation();
    vector<CIndividual*> selection();
    vector<CIndividual*> crossover(vector<CIndividual*> parents);
    void mutation();
    void evaluatePopulation();
    CIndividual getBestSolution();
    void printActualGeneration();
    void printNoSolution();
    int selectFirstParent(int parent11, int parent12);
    int selectSecondParent(int parent21, int parent22, int parent1);
    void startMessage();


public:
    CGeneticAlgorithm(int populationSize, float crossoverProbability, float mutationProbability, int numberOfGenerations, CKnapsackProblem problem);
    void solve();
    
};
