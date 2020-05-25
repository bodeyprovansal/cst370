//============================================================================
// Title       : hw1_1.cpp
// Author      : Bodey Provansal
// Abstract    : Finds the closest difference between two numbers given by an
//               input txt file
// ID          : 1013
// Date        : 1/7/2020
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


int main() {
	ifstream ioFile;
	string inFileName;
	string line;
	int lineCount = 0;
	int iter = 0;
	int x = 0;
	int * input;
	int srtPoint;
	int endPoint;
	int minDist;

	//User input/output
	cout << "Please Enter filename" << "\n";
	cin >> inFileName;
	cout << "Filename Entered: " << inFileName << "\n";

	//First Open to get number of lines in file
	ioFile.open(inFileName);
	if(ioFile.is_open()){
		while(getline(ioFile, line)) {
			if(line.length() != 0){
				lineCount += 1;
			}
		}
	} else {
		cout << "Could not open file.";
	}
	ioFile.close();
	//Allocates a block of memory with size equal to the amount of lines in txt file
	input = new int[lineCount];

	//Second open to record all values into dynamic memory
	ioFile.open(inFileName);
		if(ioFile.is_open()){
			while (ioFile >> x){
				input[iter] = x;
				iter += 1;
			}

		} else {
			cout << "Could not open file.";
		}
		ioFile.close();

		for (int i = 0; i < lineCount; i++) {
				for (int j = 0; j < lineCount; j++) {
					int currDist = abs(input[i] - input[j]);

					if ((currDist < minDist) && currDist > 0) {
						minDist = currDist;
						srtPoint = input[i];
						endPoint = input[j];
					}
				}
		}
		cout << "Min Distance: " << minDist << "\n";
		cout << "Two numbers for min distance: " << srtPoint << " and " << endPoint << "\n";

	return 0;
}
