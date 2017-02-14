#include <iostream>
#include <math.h>

using namespace std;

void printNums1ToN(int n) {

	for(int i = 1; i < n; i++) {
		cout << i << ", ";
	}
	cout << n << endl;

}

void xSquared1ToN(int n) {

	for(int i = 1; i < n; i++) {
		cout << i * i << ", ";
	}
	cout << n * n << endl;
	
}

void twoToTheN1ToN(int n) {
	
	for(int i = 1; i < n; i++) {
		cout << pow(2, i) << ", ";
	}
	cout << pow(2, n) << endl;
	
}

double factorial(int n) {
	
	double sol = 1;

	for(int i = n; i >= 1; i--) {
		sol *= i;
	}
	return sol;
	
}

void factorial1ToN(int n) {
	for(int i = 1; i < n; i++) {
		cout << factorial(i) << ", ";
	}
	cout << factorial(n) << endl;
}
	
	

int main() {

	factorial1ToN(100);
	twoToTheN1ToN(100);

}