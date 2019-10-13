#include "insertionSort.h"
#include <vector>

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