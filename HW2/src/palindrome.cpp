//============================================================================
// Title       : palindrome.cpp
// Author      : Bodey Provansal
// Abstract    : Checks whether or not user input is a palindrome.
// ID          : 1013
// Date        : 1/14/2020
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int inputNum = 0;
	int beg, end;
	char * inputF;
	char * inputB;
	string input;
	int inputLen;

	bool alive = true;
	while(alive) {
		inputNum++;
		cout << "Input String " << inputNum << ": ";
		cin >> input;
		inputLen = input.size();
		end = inputLen - 1;
		inputF= new (nothrow) char[inputLen];
		inputB= new (nothrow) char[inputLen];
		if (inputF == nullptr) {
			cout << "Error: memory could not be allocated.";
		} else {
			for (int beg = 0; beg < inputLen; beg++){
				inputF[beg] = input[beg];
				inputB[beg] = input[end];
				end--;
			}
			//cout << "Input " << inputNum << " forwards: " << inputF << "\n";
			//cout << "Input " << inputNum << " backwards: " << inputB << "\n";

			if ( strcmp(inputF, inputB) == 0) {
				cout << "Yes, this is a palindrome." << "\n";
			} else {
				cout << "No, this is not a palindrome." << "\n";
			}

		}
	}

	return 0;
}
