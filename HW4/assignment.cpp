//============================================================================
// Title       : assignment.cpp *Could not finish*
// Author      : Bodey Provansal
// Abstract    : *Intended* Input Amount of jobs, equal # of people, cost/job/person.  
//				  Output optimal cost per combination of job and person. 
//			      *Could not finish assignment in time. 
// ID          : 1013
// Date        : 02/04/2020
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <list>
#include <vector>
#include <iterator>
#include <sstream>
using namespace std;

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

void print(vector<int> g) {
	vector <int> :: iterator it; 
    for(it = g.begin(); it != g.end(); ++it) 
        cout << '\t' << *it; 
    cout << '\n';
}

void minCost(vector<vector<int>> a) {
	int n = a.size();
	int minCost = 0;
	int tempCost = 0;
	int permutation = 1;
	int* indArr = new int[n];
	int* minArr = new int[n];
	for(int i = 0; i < n; i++) {
		indArr[i] = 0;
		minArr[i] = a[i][i];
		minCost += minArr[i];
	}
	
	bool searching = true;
	
	while(searching) {
		
		for (int i = 0; i < n; i++) {
            cout << "Permutation " << permutation << ": <";
			cout << a[i][i] << " "; 
            cout << endl; 
			tempCost += a[i][i];
			cout << "> => total cost: ";
			if(tempCost < minCost) {
				minArr[i] = a[i][i];
			}
			cout << tempCost << "\n";
		}
		
		int next = n - 1;
		
		while (next >= 0 && (a[next].size())) { next--;}
		
		if(next < 0) {searching = false;}
		
		for (int i = next + 1; i < n; i++) {
			indArr[i] = 0;
		}			
		
		
	}
	
	for (int i = 0; i < n; i++) {
		cout << "Solution: <";
	}
}

int main() {
	ifstream ioFile;
	string inFileName;
	string line;
	int totalJobs;
	int cost = 0;
	int person = 0;
	
	vector<vector<int>> peopleXCosts;
	vector<string> personICosts;
	//User input
	cout << "Enter number of jobs: ";
	cin >> totalJobs;
	peopleXCosts.resize(totalJobs);
	cout << "Enter assignment costs of " << totalJobs << " persons: " << "\n";

	while(person != totalJobs) {
		getline(cin, line);
		cout << "Person " << person + 1 << ": ";
		
		personICosts = split(line, ' ');

		for (int i = 0; i < personICosts.size(); i++) {
					cost = stoi(personICosts[i]);
					peopleXCosts[person][i] = cost;
		}
		cout << "\n";
		print(peopleXCosts[person]);
		person++;
	}
	

	
	return 0;
}


