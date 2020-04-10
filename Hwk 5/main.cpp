
#include <vector>
#include <string>
#include <string.h>
#include <stdio.h>
#include <fstream>
#include <iostream>
#include <map>

using std::endl;
using std::cout;
using std::cin;

#define SIZE 100000 
std::vector<int> adj[SIZE];//adjacency matrix
int babyfaces[SIZE];
bool visited[SIZE];

bool bfs(int pos, int parent)
{
	
	visited[pos] = 1; //set position to visited
	int i, value;
	
	babyfaces[pos] = 1 - babyfaces[parent]; //set node value to different from parent
	
	for (i = 0; i < adj[pos].size(); i++) //move through adjacency matrix
	{
		value = adj[pos][i];
		
		if (!visited[value]) //if not visited, call bfs recursively
		{
			bfs(value, pos);
		}
		else
		{
			
			if (babyfaces[value] == babyfaces[pos]) //if two connected nodes share values, required rivalry conditions can't be established
				return false;
		}
	}
	return true;

}


int main(int argc, char* args[])
{
	
	int n, j, k, u, v, r; //declare all variables
	std::string babyname, rival1, rival2;
	bool possible = 1;
	
	std::map<std::string, int> data; //create map
	
	std::ifstream infile(args[1]); //open input file
	
	if (!infile) { //state if file cannot be opened
		cout << "Error opening file\n";
		return 0;
	}
	
	infile >> n; //read number of wrestlers
	
	std::string names[n + 1]; //create array to hold names as string
	
	for (int i = 0; i < n; i++) //read names from input file
	{
		infile >> babyname;
		data[babyname] = i;
		names[i] = babyname;
	}
	
	infile >> r; //get number of rivalries
	
	for (int i = 0; i < r; i++) //read the rivalries, alternating between one and the other
	{
		infile >> rival1 >> rival2;
		
		u = data[rival1];
		
		v = data[rival2];
		
		adj[u].push_back(v); //add edges
		adj[v].push_back(u);
	}
	
	infile.close(); //close file
	
	memset(babyfaces, 0, sizeof babyfaces); //set default values
	
	memset(visited, 0, sizeof visited);
	
	babyfaces[0] = 0;

	for (int i = 0; i < n; i++) //call bfs for all
	{
		if (visited[i])
			continue;
		possible = bfs(i, 0);
		
		if (!possible) //if not even, can't partition and establish designations
			break;
	}
	
	if (!possible) //let user know if not possible
	{
		cout << "No" << endl;
	}
	else
	{
		
		std::vector<std::string> faces, heels; //declare containers for names

		for (int i = 0; i < n; i++)
		{
			
			if (babyfaces[i]) //if value is 1, push name to babyfaces 
				faces.push_back(names[i]);
			else
				heels.push_back(names[i]); //if value is 0, push name to heels
		}
		cout << "Yes\n";
		cout << "Babyfaces: ";
		
		for (int i = 0; i < faces.size(); i++) //print babyfaces
			cout << faces[i] << " ";
		cout << endl;
		
		cout << "Heels: ";
		for (int i = heels.size() - 1; i >= 0; i--) //print heels
			cout << heels[i] << " ";
		cout << endl;

	}

	return 0;
}
