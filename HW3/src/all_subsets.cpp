//============================================================================
// Title       : all_subsets.cpp
// Author      : Bodey Provansal
// Abstract    : Input n. Output 2 ^ n. Uses recursive function "power".
// ID          : 1013
// Date        : 1/19/2020
//============================================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int power(int n) {
	if (n > 0 ) {
		return power(n-1) * 2;
	} else return 1;
}



int main() {
	//int inputSize;
	//int subsetSize;
	//char * input;
	//char * result;
	int inputSize;
	int inputSize2;
	string cmdInput;
	string cmdInput2;
	vector<char> input;
	vector<char> input2;
	vector<vector<char> > result;
	cout << "Number of input characters: ";
	cin >> inputSize;
	cout << "Enter " << inputSize << " characters: ";
	cin >> cmdInput;
	int i = 0;
	int j = 0;
	while(cmdInput[i]){
		input.push_back(cmdInput[i]);
		i++;
	}
	cout << "Num Characters: "<< inputSize << " Input: ";
	i = 0;
	while(input[i]) {
		cout << input[i];
		i++;
	}


	cout << "Number of input characters: ";
		cin >> inputSize2;
		cout << "Enter " << inputSize2 << " characters: ";
		cin >> cmdInput2;
		int i2 = 0;
		int j2 = 0;
		while(cmdInput2[i2]){
			input2.push_back(cmdInput2[i2]);
			i2++;
		}
		cout << "Num Characters: "<< inputSize2 << " Input2: ";
		i2 = 0;
		while(input2[i2]) {
			cout << input2[i2];
			i2++;
		}

	//result = subset(input);

	i = 0;
	while(input[i] && input2[i]) {
		result[0].push_back(input[i]);
		result[1].push_back(input2[i]);
		i++;
	}
	i = 0;
	j = 0;
	/*while(result[i][j]) {
			while(result[i][j]){
				cout << result[i][j];
				j++;
			}
			i++;
		}*/

	for (int i = 0; i < 16; i++) {
	        for (int j = 0; j < 16; j++)
	            cout << result[i][j] << " ";
	        cout << endl;
	    }

	for (int i = 0; i < 16; i++) {

	        cout << result[i][j] << " ";
	        cout << endl;
	    }
	return 0;
}
