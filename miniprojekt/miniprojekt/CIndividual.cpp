#include "CIndividual.h"


CIndividual::CIndividual(CKnapsackProblem problem)
{
    viGenotype = generateGenotype(problem.getNumberOfItems());
    ckpProblem = problem;
};


CIndividual::CIndividual(CKnapsackProblem problem, vector<int> genotype)
{
    viGenotype = genotype;
    ckpProblem = problem;
    
};


CIndividual::CIndividual(const CIndividual& other)
{
    viGenotype = other.viGenotype;
    ckpProblem = other.ckpProblem;
    
}

CIndividual::~CIndividual()
{
}


int CIndividual::calculateValue()
{
    
    return ckpProblem.calculateSolutionValue(viGenotype);
};


int CIndividual::calculateSize()
{

    return ckpProblem.calculateSolutionSize(viGenotype);
};


void CIndividual::mutate(float mutProb)
{
    for (int i = 0; i < viGenotype.size(); i++)
    {
        if (randomGenerator.generateFloat(0.0, 1.0) < mutProb)
        {
            viGenotype[i] = (viGenotype[i] + 1) % 2;
        }
    }
};


vector<CIndividual*> CIndividual::cross(CIndividual* other, float crossProb)
{
    if (randomGenerator.generateFloat(0.0, 1.0) < crossProb)
    {
        int partingPoint = randomGenerator.generateInt(0, viGenotype.size());

        for (int i = 0; i < partingPoint; i++)
        {
            int temp = other->viGenotype[i];
            other->viGenotype[i] = viGenotype[i];
            viGenotype[i] = temp;
        }
    }

    vector<CIndividual*> result;
    result.push_back(new CIndividual(ckpProblem, viGenotype));
    result.push_back(new CIndividual(ckpProblem, other->viGenotype));

    return result;
};



vector<int> CIndividual::generateGenotype(int size)
{
    vector<int> result;

    for (int i = 0; i < size; i++)
    {
        result.push_back(randomGenerator.generateInt(0, 1));
    }

    return result;
}


void CIndividual::printSolution()
{

    cout<<"    solution: ";

    for (int i = 0; i < viGenotype.size(); i++)
    {
        cout << viGenotype[i];
    }

    cout << "  value: " << calculateValue() << "  size: " << calculateSize();
    cout << "\n\n";
}


