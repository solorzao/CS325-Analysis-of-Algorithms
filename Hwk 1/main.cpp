#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "insertionSort.h"
#include "mergeSort.h"

using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;




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
			//outFileName = "merge.txt";

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




