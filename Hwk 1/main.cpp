#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;

void insertionSort(std::vector<int> &, int);
std::vector<int> merge(std::vector<int> left, std::vector<int> right);
std::vector<int> mergeSort(std::vector<int>& vec);

int main()
{
	std::string outFileName, inFileName, filetype = ".txt";
	ifstream inputFile;
	ofstream outputFile;
	bool done = false;

	do
	{
		cout << "\nPlease enter the name of the text file you would like to open." << endl;

		getline(cin, inFileName);

		inputFile.open(inFileName);

		if (!inputFile)
		{
			cout << "\nCould not access file. Please check your file name and try again.";
		}

		else
		{
			int currentNumber;
			int numberToSort;

			std::vector<int> numbersVector;

			outFileName = "insert.txt";
			//outFileName= "merge.txt";

			outputFile.open(outFileName); //open outputfile

			while (!inputFile.eof()) //keep looping until end of file is reached
			{
				inputFile >> numberToSort;
				cout << "numbers to sort: " << numberToSort << endl;

				for (int i = 0; i < numberToSort; i++) //move through input until new line is reached, add each int to vector
				{
					inputFile >> currentNumber;
					numbersVector.push_back(currentNumber);
					cout << "number read: " << currentNumber << endl;
				}

				insertionSort(numbersVector, numberToSort); //call insertion sort on vector
				//mergeSort(numbersVector);

				cout << "The sorted numbers are: " << endl;

				for (int i = 0; i < numbersVector.size(); i++)
				{
					cout << numbersVector[i] << endl;
				}
				if (outputFile.is_open())
				{
					for (int i = 0; i < numbersVector.size(); i++) //write sorted list to output file
					{
						outputFile << numbersVector[i] << " ";
					}

					outputFile << endl; //create new line
				}

				numbersVector.clear(); //clear vector for next line of input
				

			}

			done = true; //set once EOF is reached

		}

		inputFile.close(); //close files
		outputFile.close();

	} while (!done); //loop until finished going through input file

	return 0;
}

void insertionSort(std::vector<int> &vec, int n)
{
	int i, j, key;

	for (i = 0; i < n; i++) //establish key value, set j to index left of key, loop to end
	{
		key = vec[i];
		j = i - 1;

		while (j >= 0 && vec[j] > key) // loop while value at index is greater than key
		{
			vec[j + 1] = vec[j]; //swap if greater than key
			j = j - 1; //decrement index j, move left
		}
		vec[j + 1] = key; //new key value to right of j
	}
}

std::vector<int> merge(std::vector<int> left, std::vector<int> right)
{
	int posLeft = 0, posRight = 0; //create int for tracking position of left/right separately

	std::vector<int> mergedList; //create new vector for merged list

	while (posLeft < left.size() && posRight < right.size())
	{
		if (left[posLeft] < right[posRight])
		{
			mergedList.push_back(left[posLeft]); //if left is smaller, push to list, increment position
			posLeft++;
		}
		else
		{
			mergedList.push_back(right[posRight]); //if right is smaller, push to list, increment position
			posRight++;
		}
	}
	while (posLeft < left.size())
	{
		mergedList.push_back(left[posLeft]); //if left still has not reached end, push rest of values to list
		posLeft++;
	}
	while (posRight < right.size())
	{
		mergedList.push_back(right[posRight++]); //if right still has not reached end, push rest of values to list
	}
	return mergedList; //return merged list
}

std::vector<int> mergeSort(std::vector<int>& vec)
{
	if (vec.size() <= 1)
	{
		return vec; //if vector contains 1 element, can't be split (base case)
	}

	int len = vec.size() / 2; //get halfway point for vector

	std::vector<int> left(vec.begin(), vec.begin() + len); //create new vector from beginning to half
	std::vector<int> right(vec.begin() + len, vec.end()); //create new vector from half to end

	return merge(mergeSort(left), mergeSort(right)); //call merge for two halves recursively
}
