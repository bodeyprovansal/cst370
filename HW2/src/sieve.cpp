//============================================================================
// Title       : sieve.cpp
// Author      : Bodey Provansal
// Abstract    : Performs the sieve of Eratosthenes algorithm.
// ID          : 1013
// Date        : 1/14/2020
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int input;
	int p;
	int j;
	int i = 0;
	int* A;
	int* L;
		cout << "Enter an integer greater than 1." << "\n";
		cin >> input;
		cout << "Input number: " << input << "\n";

		//Full Integer Array from 2 to n
		A = new (nothrow) int[input];
		//Array of Prime Integers
		L = new (nothrow) int[input - 1];
		A[0] = 0;
		A[1] = 0;

		//Initialize full array or prime & non-prime numbers from 2 to input.
		for (p = 2; p <= input; p++) {
			A[p] = p;
		}
		//Find Prime Integers, set all others to 0
		for (p = 2; p <= floor(sqrt(input)); p++){
			if (A[p] != 0) {
				j = p * p;
				while (j <= input) {
					A[j] = 0;
					j = j + p;
				}
			}
		}
		//Transfer all non-zero elements in A to L
		for (p = 2; p <= input; p++) {
			if (A[p] != 0) {
				L[i] = A[p];
				i++;
			}
		}
		//Print all elements in L
		cout << "Output array: ";
		for (int x = 0; x < i; x++) {
			if ((x != i-1) && (L[x] <= input)) {
				cout << L[x] <<", ";
			} else if((x == i-1) && (L[x] > 0)) {
				cout << L[x];
			}
		}

	delete[] A;
	delete[] L;
	return 0;
}
