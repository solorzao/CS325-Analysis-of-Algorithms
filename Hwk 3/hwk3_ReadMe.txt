Program written in C++ that implements a dynamic programming algorithm to solve a 0-1 knapsack problem. 

main.cpp relies on a file from the same directory named "data.txt". The input filename is hardcoded so it won't work if that exact filename isn't present. It will give an error citing lack of an appropriate input file.  

Compilation Notes: Uses ISO c++ 2011 standard (necessary for some C++ library functions to run). Compiled on OSU engineering server using -std=c++11 command.

Command to compile the program: g++ -std=c++11 main.cpp  -o knapSack
