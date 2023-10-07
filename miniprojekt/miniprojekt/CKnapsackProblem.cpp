#include "CKnapsackProblem.h"

CKnapsackProblem::CKnapsackProblem() {}

CKnapsackProblem::CKnapsackProblem(int numberOfItems, int backpackCapacity, vector<int> itemSizes, vector<int> itemValues)
{
	valueCheck.checkInt(numberOfItems, 1, "Number of items");
	valueCheck.checkInt(backpackCapacity, 1, "Backpack Capacity");

	checkVectors(itemSizes, itemValues, numberOfItems);

	iNumberOfItems = numberOfItems;
	iBackpackCapacity = backpackCapacity;
	vItemSizes = itemSizes;
	vItemValues = itemValues;

	cout << "New knapsack problem created" << "\n";

	messageAfterLoad();
}


CKnapsackProblem::CKnapsackProblem(string fileName)
{
	loadFromFile(fileName);

	cout << "Knapsack problem loaded form file " << "\n";

	messageAfterLoad();
	
}


int CKnapsackProblem::getNumberOfItems()
{
	return iNumberOfItems;
}


int CKnapsackProblem::calculateSolutionValue(vector<int> genotype)
{
	int sumValue = 0;
	int sumSize = 0;

	for (int i = 0; i < genotype.size(); i++)
	{
		if (genotype[i] == 1)
		{
			sumValue += vItemValues[i];
			sumSize += vItemSizes[i];
		}
	}

	if (sumSize > iBackpackCapacity) return -1;
	else return sumValue;
	
}


int CKnapsackProblem::calculateSolutionSize(vector<int> genotype)
{
	int sumSize = 0;

	for (int i = 0; i < genotype.size(); i++)
	{
		if (genotype[i] == 1)
		{
			sumSize += vItemSizes[i];
		}
	}

	return sumSize;

}


void CKnapsackProblem::loadFromFile(string fileName) 
{
	ifstream file;
	file.open(fileName, ios::in);

	if (file.fail()) throw "File is failing to open!";

	int knapsackCapacity;
	file >> knapsackCapacity;

	valueCheck.checkInt(knapsackCapacity, 1, "Kanpsack Capacity");

	iBackpackCapacity = knapsackCapacity;

	int numberOfItems;
	file >> numberOfItems;

	valueCheck.checkInt(numberOfItems, 1, "Number of items");

	iNumberOfItems = numberOfItems;


	vector<int> sizes;
	vector<int> values;
	int size, value;

	while (file >> size >> value) {
		sizes.push_back(size);
		values.push_back(value);
	}

	checkVectors(sizes, values, numberOfItems);

	vItemValues = values;
	vItemSizes = sizes;

	file.close();
}


void CKnapsackProblem::checkVectors(vector<int> sizes, vector<int> values, int numberOfItems)
{
	if (sizes.size() != values.size()) throw "Number of sizes and values is not the same!";

	if (sizes.size() != numberOfItems) throw "Number of sizes and number of items is not the same!";

	for (int i = 0; i < numberOfItems; i++)
	{
		valueCheck.checkInt(sizes[i], 1, "Size of item");
		valueCheck.checkInt(values[i], 0, "Value of item");
	}
}

void CKnapsackProblem::messageAfterLoad()
{
	cout << "Knapsack capacity: " << iBackpackCapacity << "\n";
	cout << "Number of items to pack: " << iNumberOfItems << "\n";

	cout << "Items to pack: "  << "\n";

	for (int i = 0; i < iNumberOfItems; i++)
	{
		cout << "Item number " << i + 1 << " size: " << vItemSizes[i] << "  value: " << vItemValues[i]<<"\n";
	}
}
