//============================================================================
// Title       : BFS.cpp
// Author      : Bodey Provansal
// Abstract    : Input is a txt file with an adjecency matrix for a graph. 
//			     Output will give Breadth First Search Order from a starting 
//				 vertex.
// ID          : 1013
// Date        : 2/03/2020
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include <vector>
#include <iterator>
#include <sstream> 
using namespace std;

//Lines 23 - 37 used from:
//https://stackoverflow.com/questions/236129/how-do-i-iterate-over-the-words-of-a-string
template <typename Out>
void split(string s, char delim, Out result) {
    istringstream iss(s);
    string item;
    while (getline(iss, item, delim)) {
        *result++ = item;
    }
}
//takes in a string and delimiter char
//recursively calls above split function to split string at delim char
//returns as elements in a vector
vector<string> split(string s, char delim) {
	vector<string> elems;
	split(s, delim, back_inserter(elems));
	return elems;
}	

void BFS(vector<list<int>> a, int s, int v) {
	//Vector of visited vertices
	vector<bool> visited(v);
	//Our "stack", will be using a queue structure
	list<int> queue;
	//Visit the starting vertex and add to stack
	queue.push_back(s);
	visited[s] = true;
	cout << "BFS Order: " << s;
	//Create an iterator for the "stack"
	list<int>::iterator queIter;
	//repeat until we have an empty stack
	while(!queue.empty()){
		//Check adjacency for vertex at front of queue, then pop
		s = queue.front();
		queue.pop_front();
		//iterates through list of vertices adjecent to s
		for (queIter = a[s].begin(); queIter != a[s].end(); ++queIter) {
			//vertex #s are represented by the index of the visited list
			//If we have not visited this vertex, 
			//add it to the stack, mark as visited, and print result
			if(!visited[*queIter]) {
				queue.push_back(*queIter);
				visited[*queIter] = true;
				cout << " -> " << *queIter;
			}
		}
	}
}

int main() {
	ifstream ioFile;
	string inFileName;
	string line;
	int vertexCount = 0;
	//row = vertex, col = vertices adjectent to row vertex
	int row = 0;
	int col = 0;
	//starting vertex #
	int start = 0;
	vector<list<int>> adjList;
	vector<string> lineVec;
	string space = " ";
	//User input
	cout << "Please Enter filename: ";
	cin >> inFileName;
	cout << "Enter a start vertex: ";
	cin >> start;

	//Open File. 
	ioFile.open(inFileName);
	if(ioFile.is_open()){
		while(getline(ioFile, line)) {
			//split line into seperate adjacency values
			lineVec = split(line, ' ');
			//Our first line will be size 1 and give size of adjList
			if(lineVec.size() == 1) {
				vertexCount = stoi(lineVec.at(0));
				adjList.resize(vertexCount);
			} else {
				//iterate through each line, if true (1)
				//there is an edge from row vertex to col vertex
				for (int i = 0; i < lineVec.size(); i++) {
					col = stoi(lineVec.at(i));
					if (col == 1) {adjList[row].push_back(i);}
				}
				//Move onto next row/next getline()
				row++;
			}
		}
	} else {
		cout << "Could not open file.";
	}
	BFS(adjList, start, vertexCount);

	ioFile.close();
	return 0;
}


