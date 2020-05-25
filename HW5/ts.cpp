//============================================================================
// Title       : ts.cpp
// Author      : Bodey Provansal
// Abstract    : Input is a txt file with an adjecency matrix for a graph. 
//			     Output will give topologic sorting order of graph. 
//				 
// ID          : 1013
// Date        : 2/11/2020
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include <vector>
#include <queue>
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

void topOrder(vector<list<int>> a, int v) {
	
	vector<int> sourceCount(v, 0);
	vector<int> topOrder;
	queue<int> sources;
	
	//Matches adjList index with number of sources into that Node
	list<int>::iterator sourceIter;
	for(int i = 0; i < v; i++) {
		for(sourceIter = a[i].begin(); sourceIter != a[i].end(); sourceIter++){
			sourceCount[*sourceIter]++;
		}
	}
	//Fill our queue with vertices that do not have incoming sources
	//i.e. create our list of sources for other nodes
	for(int j = 0; j < v; j++) {
		if(sourceCount[j] == 0){
			sources.push(j);
		}
	}
	//While we have indices 
	while(!sources.empty()) {
		int thisSource = sources.front();
		//"delete" current source from graph
		sources.pop();
		//add this source to our topological order
		topOrder.push_back(thisSource);
		//iterate through this sources adjacent nodes
		list<int>::iterator topIter;
		for(topIter = a[thisSource].begin(); topIter != a[thisSource].end(); topIter++) {
			//since we deleted a node, decrease every node's amount of sources by 1
			sourceCount[*topIter] -= 1;
			//if this adjecent node now has no in-sources, add it to our list of source nodes
			if(sourceCount[*topIter] == 0) {
				sources.push(*topIter);
			}
		}
	}
	
	if(topOrder.size() > v) {
		cout << "Visted more nodes than were given. Likely a cycle in the graph." << "\n";
	} else {
		cout << "Topological Sort: ";
		for(int k = 0; k < topOrder.size(); k++) {
			if(k > 0) {cout << " -> ";}
			cout << topOrder[k] ;
		}
		cout << "\n";
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
	vector<list<int>> adjList;
	vector<string> lineVec;
	string space = " ";
	//User input
	cout << "Please Enter filename: ";
	cin >> inFileName;

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
	topOrder(adjList, vertexCount);
	
	ioFile.close();
	return 0;
}


