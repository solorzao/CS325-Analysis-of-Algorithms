#include "mergeSort.h"
#include <vector>;

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