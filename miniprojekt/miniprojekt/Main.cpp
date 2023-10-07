#include <iostream>
#include "CKnapsackProblem.h"
#include "CIndividual.h"
#include "CGenericAlgorithm.h"
using namespace std;

void example1()
{
	vector<int> sizes;
	sizes.push_back(4);
	sizes.push_back(1);
	sizes.push_back(3);
	sizes.push_back(2);
	vector<int> values;
	values.push_back(5);
	values.push_back(1);
	values.push_back(4);
	values.push_back(3);
	CKnapsackProblem problem(4, 5, sizes, values);
	CGeneticAlgorithm ag(8, 0.6, 0.1, 100, problem);
	ag.solve();
}


void example2()
{
	CKnapsackProblem problem("C:\\Users\\kcbal\\Desktop\\eclipse\\problemknapsack1.txt");
	CGeneticAlgorithm ag(20, 0.6, 0.1, 100, problem);
	ag.solve();
}


void example3()
{
	CKnapsackProblem problem("C:\\Users\\kcbal\\Desktop\\eclipse\\problemknapsack2.txt");

	CGeneticAlgorithm ag(50, 0.6, 0.1, 200, problem);
	ag.solve();
}


void example4()
{
	CKnapsackProblem problem("C:\\Users\\kcbal\\Desktop\\eclipse\\problemknapsack3.txt");

	CGeneticAlgorithm ag(20, 0.6, 0.1, 100, problem);
	ag.solve();
}


int main()
{
	//example1();
	//example2();
	//example3();
	example4();
}