//============================================================================
// Title       : power.cpp
// Author      : Bodey Provansal
// Abstract    : Input n. Output 2 ^ n. Uses recursive function "power".
// ID          : 1013
// Date        : 1/19/2020
//============================================================================

#include <iostream>
using namespace std;

int power(int n) {
	if (n > 0 ) {
		return power(n-1) * 2;
	} else return 1;
}

int main() {
	int input;
	cout << "Enter a number: ";
	cin >> input;
	input = power(input);
	cout << "Result: " << input;
	return 0;
}


