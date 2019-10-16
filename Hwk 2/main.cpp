#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "stoogeSort.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ifstream;

int main()
{
	std::string outFileName, inFileName;
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
			int currentNumber, numberToSort;

			std::vector<int> numbersVector;

			outFileName = "stooge.txt"; //name output file

			outputFile.open(outFileName); //open outputfile

			while (!inputFile.eof()) //keep looping until end of file is reached
			{
				inputFile >> numberToSort;
				cout << "Numbers to sort: " << numberToSort << endl;

				for (int i = 0; i < numberToSort; i++) //move through input until new line is reached, add each int to vector
				{
					inputFile >> currentNumber;
					numbersVector.push_back(currentNumber);
					cout << "Number read: " << currentNumber << endl;
				}

				int rightmost = numbersVector.size() - 1; //determine leftmost and rightmost to pass to sort function
				int leftmost = 0;

				stoogeSort(numbersVector, leftmost, rightmost); //call insertion sort on vector

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




