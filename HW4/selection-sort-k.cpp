//============================================================================
// Title       : selection-sort-k.cpp
// Author      : Bodey Provansal
// Abstract    : Input is a txt file with a list of numbers. Output will sort 
//				 input using selection sort algorithm in a constant k time. 
// ID          : 1013
// Date        : 02/02/2020
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void selSort(int A[], int k, int size) { //takes in array, kth element, and input size
	for (int i = 0; i < k; i++) {
		int min = i; //update min each loop to leave previous "i"s alone
		int temp = 0;
		for (int j = i + 1; j < size; j++) {
			if(A[j] < A[min]) {min = j;} //get min index
		}
		temp = A[i]; //swap min value with ith value
		A[i] = A[min];
		A[min] = temp;
	}	
}

int main() {
	ifstream ioFile;
	string inFileName;
	string line;
	int lineCount = 0;
	int iter = 0;
	int x = 0;
	int * input;
	int firstK = 0;

	//User input
	cout << "Please Enter filename: ";
	cin >> inFileName;
	cout << "Enter the value k: ";
	cin >> firstK;

	//Open File. Get first line, convert to int, allocate memory of 
	//size of first line
	ioFile.open(inFileName);
	if(ioFile.is_open()){
		getline(ioFile, line);
		lineCount = stoi(line);
		input = new int[lineCount + 1];
		while (ioFile >> x){ //store lines into array
			input[iter] = x;
			iter += 1;
		}
		selSort(input, firstK, lineCount); //sorts input array up to k elements
		cout << "Output: ";
		for (int k = 0; k < firstK; k++){ //output sorted array
			cout << input[k];
			if(k < firstK - 1)
			{
				cout << ", ";
			}
		}
	} else { //errors out if input file does not exist
		cout << "Could not open file.";
	}
	
	ioFile.close();

	return 0;
}


