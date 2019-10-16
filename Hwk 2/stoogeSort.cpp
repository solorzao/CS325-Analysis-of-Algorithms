#include "stoogeSort.hpp"
#include <vector>

void stoogeSort(std::vector<int> &vec, int l, int r)
{
	if (l >= r) //base case
	{
		return;
	}

	if (vec[l] > vec[r]) //if leftmost is greater than right, swap
	{
		int temp;
		temp = vec[r];
		vec[r] = vec[l];
		vec[l] = temp;
	}
	
	if ((r - l + 1) > 2) //if there are more than two values in the vector
	{
		int t = ((r - l + 1) / 3); //get size of third of array

		stoogeSort(vec, l, (r - t)); //recursively sort first 2/3 elements
		stoogeSort(vec, (l + t), r); //recursively sort last 2/3 elements
		stoogeSort(vec, l, (r - t)); //recursively sort first 2/3 elements
	}

}
