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
	

int main() {

	twoToTheN1ToN(100);

}