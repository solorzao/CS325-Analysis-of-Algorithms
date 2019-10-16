#include <string>
#include <iostream>
#include <vector>
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>
#include <chrono>

#include "stoogeSort.hpp"

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
		currentNumber = rand() % 10001; //generate random int between 0-10000
		numbersVector.push_back(currentNumber);					
	}
	
	int leftmost = 0; //determine leftmost and rightmost values
	int rightmost = n - 1;

	auto start = high_resolution_clock::now(); //get system time before function call
	
	stoogeSort(numbersVector, leftmost, rightmost); //call stoogeSort on vector
	
	auto stop = high_resolution_clock::now(); //get system time after function call

	auto duration = duration_cast<microseconds>(stop - start); //get difference between system times to get runtime

	cout << "\nThe size of the array that was sorted is: " << n << endl;

	cout << "\nThe time it took to sort was: " << duration.count() << " microseconds." << endl;

	return 0;
}




