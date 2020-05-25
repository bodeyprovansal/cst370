//============================================================================
// Title       : Prim.cpp **not complete**
// Author      : Bodey Provansal
// Abstract    : Attempts to organize input into list of connected edges and 
//				 associated costs to perform Prim's algorithm to find MST. 
//				 Prim's algorithm is attempted but not implemented correctly. 
// ID          : 1013
// Date        : 2/25/2020
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include <vector>
#include <iterator>
#include <sstream> 
using namespace std;
#define MAX 999

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

void displayMatrix(vector<vector<int>> &vect){
	for (int i = 0; i < vect.size(); i++) { 
        for (int j = 0; j < vect[i].size(); j++) 
            cout << vect[i][j] << " "; 
        cout << endl; 
    } 
}

void prim(vector<vector<int>> &M, int primStart, int vCount, int eCount) {
	cout << "calling prim.." << endl;
	vector<vector<int>> primMatrix(vCount, vector<int>(3, 0));
	int minCost = MAX;
	int currStart = 0;
	int currEnd = 0;
	for(int i = 1; i < vCount; i++){
		minCost = MAX;
		for(int j = 0; j < eCount; j++){
			if(M[i][j] < minCost) {
				minCost = M[i][j];
				currStart = i;
				currEnd = j;
			}
		}
		primMatrix[i][0] = currStart + 1;
		primMatrix[i][1] = currEnd + 1;
		primMatrix[i][2] = minCost;
	}
	displayMatrix(primMatrix);
	for(int i = 0; i < vCount - 1; i++){
			cout << "(" << i << ") New edge: " << primMatrix[i][0] << ", " << primMatrix[i][1] << " - cost " 
			<< primMatrix[i][2] << endl;
	}
}

int main() {
	ifstream ioFile;
	string inFileName;
	string line;
	int vertexCount = 0;
	int edgeCount = 0;
	//sVert = starting vertex, e = end vertex, value at location will be cost
	int sVert = 0;
	int eVert = 0;
	int cost = 0;
	int lineNo = 0;
	//starting vertex #
	int pStart = 0;
	//vector<list<int>> adjList;
	vector<vector<int>> edgeMatrix;
	vector<string> lineVec;
	string space = " ";
	//User input
	cout << "Please Enter filename: ";
	cin >> inFileName;
	cout << "Enter a start vertex: ";
	cin >> pStart;

	//Open File. 
	ioFile.open(inFileName);
	if(ioFile.is_open()){
		while(getline(ioFile, line)) {
			//split line into seperate adjacency values
			lineVec = split(line, ' ');
			//Our first line will be size 1 and give size of adjList
			if(lineVec.size() == 1) {
				if(lineNo == 0) {
					vertexCount = stoi(lineVec.at(0));
					lineNo++;
					cout << "vertexCount: " << vertexCount << endl;
				} else {
					edgeCount = stoi(lineVec.at(0));
					lineNo++;
					cout << "edgeCount: " << edgeCount << endl;
					edgeMatrix.resize(vertexCount + 1, vector<int>(edgeCount + 1, MAX));
				}
			} else {
				sVert = stoi(lineVec.at(0));
				eVert = stoi(lineVec.at(1));
				cost = stoi(lineVec.at(2));
				edgeMatrix[sVert + 1][eVert + 1] = cost;
				cout << "sVert: " << sVert << endl;
				cout << "eVert: " << eVert <<  endl;
				cout << "cost: " << cost << endl;
			}
		}
		cout << "while loop ended" << endl;
	} else {
		cout << "Could not open file.";
	}
	displayMatrix(edgeMatrix);
	prim(edgeMatrix, pStart, vertexCount + 1, edgeCount + 1);
	cout << "exiting...";
	ioFile.close();
	return 0;
}


