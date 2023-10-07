#include "CGenericAlgorithm.h"
#include <random>

CGeneticAlgorithm::CGeneticAlgorithm(int populationSize, float crossoverProbability, float mutationProbability, int numberOfGenerations, CKnapsackProblem problem)
{
	valueCheck.checkFloat(crossoverProbability, 0.0, 1.0, "Crossover probability");
	valueCheck.checkFloat(mutationProbability, 0.0, 1.0, "Mutation probability");
	valueCheck.checkInt(populationSize, 2, "Population size");
	valueCheck.checkInt(populationSize, 1, "Number of generations");

	iPopulationSize = populationSize;
	fCrossoverProbability = crossoverProbability;
	fMutationProbability = mutationProbability;
	iNumberOfGenerations=numberOfGenerations;
	ckpProblem = problem;

	startMessage();
}

void CGeneticAlgorithm::solve()
{
	initializePopulation();

	int highestValueEverNoticed=-1;
	int highestValueGeneration = -1;

	for (int i = 0; i < iNumberOfGenerations; i++)
	{

		evaluatePopulation();

		CIndividual bestSolution = getBestSolution();

		cout << "Best solution after generation number " << i + 1 << ":";

		if (bestSolution.calculateValue() == -1);
		else bestSolution.printSolution();

		if (bestSolution.calculateValue() >= highestValueEverNoticed)
		{
			highestValueEverNoticed = bestSolution.calculateValue();
			highestValueGeneration = i + 1;
		}	
	}

	CIndividual bestSolution=getBestSolution();


	cout << "\nBest solution in the last population:";

	if (bestSolution.calculateValue() == -1);
	else bestSolution.printSolution();

	cout << "Highest fitting value ever noticed: " << highestValueEverNoticed << " in generation " << highestValueGeneration<<"\n";

	for (int i = 0; i < ciPopulation.size(); i++)
	{
		delete ciPopulation[i];
	}
}


void CGeneticAlgorithm::initializePopulation()
{
	for (int i = 0; i < iPopulationSize; i++)
	{
		ciPopulation.push_back(new CIndividual(ckpProblem));
	}
}


void CGeneticAlgorithm::evaluatePopulation()
{
	
	vector <CIndividual*> newGeneration;
	
	
	while (newGeneration.size()<iPopulationSize)
	{
		
		
		vector <CIndividual*> parents = selection();
		

		vector <CIndividual*> children = crossover(parents);
		

		newGeneration.push_back(children[0]); 
		newGeneration.push_back(children[1]);

	}

	if (newGeneration.size() > iPopulationSize)
	{
		delete newGeneration[newGeneration.size() - 1];
		newGeneration.resize(iPopulationSize);
	}

	for (int i = 0; i < ciPopulation.size(); i++)
	{
		delete ciPopulation[i];
	}

	ciPopulation = newGeneration;

	mutation();
}


vector<CIndividual*> CGeneticAlgorithm::crossover(vector<CIndividual*> parents)
{
	vector<CIndividual*> children = parents[0]->cross(parents[1], fCrossoverProbability);
	return children;
}


vector<CIndividual*> CGeneticAlgorithm::selection()
{
	vector<CIndividual*> parents;

	int parent1;
	int parent2;
	int parent11 = randomGenerator.generateInt(0, iPopulationSize-1);
	int parent12 = randomGenerator.generateInt(0, iPopulationSize - 1);
	int parent21 = randomGenerator.generateInt(0, iPopulationSize - 1);
	int parent22 = randomGenerator.generateInt(0, iPopulationSize - 1);


	while (parent11 == parent12)
	{
		parent12 = randomGenerator.generateInt(0, iPopulationSize - 1);
	}
	

	while (parent21 == parent22)
	{
		parent21 = randomGenerator.generateInt(0, iPopulationSize - 1);
	}
	

	parent1 = selectFirstParent(parent11, parent12);


	parent2 = selectSecondParent(parent21, parent22, parent1);

	
	parents.push_back(ciPopulation[parent1]);
	parents.push_back(ciPopulation[parent2]);
	return parents;
}


int CGeneticAlgorithm::selectFirstParent(int parent11, int parent12)
{
	if (ciPopulation[parent11]->calculateValue() > ciPopulation[parent12]->calculateValue()) return parent11;
	else if (ciPopulation[parent11]->calculateValue() == ciPopulation[parent12]->calculateValue() && ciPopulation[parent11]->calculateSize() <= ciPopulation[parent12]->calculateSize()) return parent11;
	else return parent12;
}


int CGeneticAlgorithm::selectSecondParent(int parent21, int parent22, int parent1)
{
	if (parent22 == parent1) return parent21;
	else if (parent21 == parent1) return parent22;
	else if (ciPopulation[parent21]->calculateValue() > ciPopulation[parent22]->calculateValue()) return parent21;
	else if (ciPopulation[parent21]->calculateValue() == ciPopulation[parent22]->calculateValue() && ciPopulation[parent21]->calculateSize() <= ciPopulation[parent22]->calculateSize()) return parent21;
	else return parent22;
}

void CGeneticAlgorithm::startMessage()
{
	cout<<"\n" << "New generic algoritm created" << "\n";
	cout << "Crossover probability: " << fCrossoverProbability << "\n";
	cout << "Mutation probability: " << fMutationProbability << "\n";
	cout << "Number of individuals in one generation: " << iPopulationSize << "\n";
	cout << "Number of generations to be generated: " << iNumberOfGenerations << "\n\n";
}


void CGeneticAlgorithm::mutation()
{
	for (int i = 0; i < iPopulationSize; i++)
	{
		ciPopulation[i]->mutate(fMutationProbability);
	}
}


CIndividual CGeneticAlgorithm::getBestSolution()
{
	int maxVal = -2;
	int indexOfBestIndividual = -1;

	for (int i = 0; i < iPopulationSize; i++)
	{
		if (ciPopulation[i]->calculateValue() > maxVal)
		{
			maxVal = ciPopulation[i]->calculateValue();
			indexOfBestIndividual = i;
		}
		else if (ciPopulation[i]->calculateValue() == maxVal && ciPopulation[i]->calculateSize() < ciPopulation[indexOfBestIndividual]->calculateSize())
		{
			maxVal = ciPopulation[i]->calculateValue();
			indexOfBestIndividual = i;
		}
	}

	return *ciPopulation[indexOfBestIndividual];
}


void CGeneticAlgorithm::printActualGeneration()
{
	cout << "\n";
	for (int i = 0; i < ciPopulation.size(); i++)
	{
		ciPopulation[i]->printSolution();
	}
	cout << "\n";
}

void CGeneticAlgorithm::printNoSolution()
{
	cout << "No solution";
	cout << "\n";
}





