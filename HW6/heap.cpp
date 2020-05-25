//============================================================================
// Title       : heap.cpp
// Author      : Bodey Provansal
// Abstract    : Performs operations on a given heap
//               
// ID          : 1013
// Date        : 2/22/2020
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

#define MAX 50

void displayHeap(int H[], int size){
	for(int i = 1; i < size; i++) {
		cout << H[i] << " ";
	}
	cout << endl;
}
//Checks if input is heap 
bool checkForHeap(int A[], int size){
	for(int i = 1; i < size / 2; i++) {
		if((A[i] < A[2 * i]) or (A[i] < A[2 * i + 1])) {
			return false;
		}
	}
	return true;
}
//heapify checks for values out of "max heap" order. If there are children nodes 
//greater than parent nodes and swaps them. 
void heapify(int A[], int size){
	//cout << "heapifying: ";
	int i, j, k, v = 0;
	bool heap;
	for(i = size / 2; i > 0; i--){
		//cout << "checking dominance for parent at index " << i << endl;
		k = i;
		v = A[k];
		heap = false;
		while ((!heap) and (2 * k < size)) {
			j = 2 * k;
			if(j < size){
				if(A[j] < A[j+1]){
					j = j + 1;
				}
			}
			if(v >= A[j]) {
				heap = true;
				//cout << "node w/ value " << v << " greater than child at index " << j << endl; 
			} else {
				//swapped unordered values;
				A[k] = A[j];
				k = j;
			}
		}				
		A[k] = v;		
	}
}

void insert(int A[], int size, int newValue) {
	//size += 1;
	A[size - 1] = newValue;
	heapify(A, size);
}

void deleteMax(int A[], int size) {
	int endOfHeap = A[size - 1];
	A[1] = endOfHeap;
	size -= 1;
	heapify(A, size);
}

void heapsort(int A[], int size) {
	int * heapsorted = new int[size];
	int i = 1;
	int n = size;
	while(size > 0){
		heapsorted[i] = A[1];
		deleteMax(A, size);
		size--;
		i++;
	}
	cout << "Heapsort: ";
	displayHeap(heapsorted, n);
}

int main() {
	string inputString;
	int inputSize = 0;
	int selection = 0;
	bool running = true;
	int newValue = 0;
	
	//User input/output
	cout << "Input Size: " << "\n";
	cin >> inputSize;
	inputSize += 1;
	int * input = new int[MAX];
	cout << "Enter Numbers: " << "\n";
	for (int i = 1; i < inputSize; ++i) {
		cin >> input[i];
	}
	//First checks for heap, heapifies if not a heap
	if(checkForHeap(input, inputSize)){
		cout << "This is a heap." <<endl;
	} else {
		cout << "This is NOT a heap." << endl;
		 heapify(input, inputSize);
		cout << "Heap constructed: ";
		displayHeap(input, inputSize);
		cout << endl;
	}
//repeats until 3. is selected	
	while(running) {
		cout << "Select an operation" << endl;
		cout << "    1. Insert a number" << endl;
		cout << "    2. Delete the max" << endl;
		cout << "    3. Heapsort & Quit" << endl;
		
		cin >> selection;
		//Insert Option
		if(selection == 1){
			cout << "Enter a number: " << endl;
			cin >> newValue;
			inputSize++;
			insert(input, inputSize, newValue);
			cout << "Updated heap: ";
			displayHeap(input, inputSize);
			cout << endl;
		//Delete Option
		} else if (selection == 2) {
			deleteMax(input, inputSize);
			inputSize--;
			cout << "Updated heap: ";
			displayHeap(input, inputSize);
			cout << endl;
		//Provides heapsort of input and exits
		} else if (selection == 3) {
			heapsort(input, inputSize);
			cout << endl;
			cout << "Bye!" << endl;
			running = false;
		}
	}
	
	delete input;
	return 0;
}
