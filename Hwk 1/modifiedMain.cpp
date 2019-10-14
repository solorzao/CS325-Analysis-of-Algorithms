#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <chrono>

#include "insertionSort.h"
#include "mergeSort.h"

using std::cout;
using std::cin;
using std::endl;
using namespace std::chrono;

int main()
{
	
	int n;
	srand(time(0));

	cout << "\nPlease enter a value for n (size of array to sort)." << endl;

	cin >> n;
		
	int currentNumber;

	std::vector<int> numbersVector;

	for (int i = 0; i < n; i++) //move through input until new line is reached, add each int to vector
	{
		currentNumber = rand() % 10001;
		numbersVector.push_back(currentNumber);					
	}
	
	auto start = high_resolution_clock::now();
	
	insertionSort(numbersVector, n); //call insertion sort on vector
	//mergeSort(numbersVector);
	
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop - start);

	cout << "\nThe size of the array that was sorted is: " << n << endl;

	cout << "\nThe time it took to sort was: " << duration.count() << " microseconds." << endl;

	return 0;
}




