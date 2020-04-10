#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;

using std::ifstream;

int max(int a, int b) { return (a > b) ? a : b; } //helper function that returns max value between two ints

int knapSackDP(int capacity, std::vector<int> weights, std::vector<int> values, int n); //function prototype

int main() {

	std::string inFileName = "data.txt";
	ifstream inputFile;
	
	int currentWeight;
	int currentValue;

	int capacity = 80; //maximum weight that we can hold
	int n = 5; //number of items

	std::vector<int> weights; //vectors to hold values and weights
	std::vector<int> values;

	bool done = false;

	do
	{
		cout << "\nThis is the solution for the optimal subset of values/weights provided by a ""data.txt"" file" << endl;

		inputFile.open(inFileName);

		if (!inputFile)
		{
			cout << "\nCould not access file. Please check your file name and try again.";
		}

		else
		{

			while (!inputFile.eof()) //keep looping until end of file is reached
			{
				inputFile >> currentWeight;
				weights.push_back(currentWeight);

				inputFile >> currentValue;
				values.push_back(currentValue);

			}

			done = true; //set once EOF is reached

		}

		inputFile.close(); //close files
		

	} while (!done); //loop until finished going through input file

	cout << "\nThe weights that were read are: " << endl;

	for (int i = 0; i < weights.size(); i++) {
		cout << i+1 << ") " << weights[i] << endl;
	}

	cout << "\nThe values that were read are: " << endl;
	for (int i = 0; i < values.size(); i++) {
		cout << i + 1 << ") " << values[i] << endl;
	}

	int maxValue = knapSackDP(capacity, weights, values, n);

	cout << "\nThe optimal value for the given data set is: $" << maxValue << endl;

	return 0;
}


int knapSackDP(int capacity, std::vector<int> weights, std::vector<int> values, int n) //return max value of 0-1 knapsack problem
{
	int K[n + 1][capacity + 1]; //declare matrix to hold values

	//create matrix to hold values gathered in bottom-up fashion
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= capacity; j++)
		{
			if (i == 0 || j == 0) { //base case, if no items or weight, no value, return 0
				K[i][j] = 0;
			}
				
			else if (weights[i - 1] <= j) { //if it can fit, continue
				K[i][j] = max(values[i - 1] + K[i - 1][j - weights[i - 1]], K[i - 1][j]); //set to whichever value is higher, prev or new
			}

			else { //if it can't fit, set to prev max value
				K[i][j] = K[i - 1][j];
			}
		}
	}

	return K[n][capacity]; //return max value
}

