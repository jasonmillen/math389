#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

unsigned int gcd (unsigned int a, unsigned int b) {
  unsigned int x;
  while (b) {
	  x = a % b;
	  a = b;
	  b = x;
  }
  return a;
}

int cube(int n) {
	return n * n * n;
}

bool vectorHasRelativePrimes(vector<int> & v) {
	for(int i = 0; i < v.size(); i++) {
		for(int j = i + 1; j < v.size(); j++) {
			if(gcd(v[i], v[j]) == 1) {
				return true;
			}

		}
	}
	return false;
}

string generateStringForm(int a, int b) {
	return to_string(a) + ", " + to_string(b);
}

void printCubes(vector<int> & v) {
	int idx = 0;
	for(int i = 0; i < v.size(); i++) {
		cout << v[i];

		if(idx == 0) {
			cout << ", ";
			idx = 1;
		}
		else {
			if(i != v.size() - 1) {
				cout << " -- ";
				idx = 0;
			}
		}
	}
	cout << endl;

}

void findSumOfCubes() {
	//unordered_map<int, string> sum_of_cubes;

	unordered_map<int, vector<int> > sum_of_cubes;

	for(int i = 0; i < 1000; i++) {
		for(int j = i; j < 1000; j++) {
			
			int cubedSum = cube(i) + cube(j);
			
			//string s = generateStringForm(i, j);

			if(sum_of_cubes.find(cubedSum) == sum_of_cubes.end()) {
				vector<int> v;
				v.push_back(i);
				v.push_back(j);
				sum_of_cubes[cubedSum] = v;
			}
			else {

				sum_of_cubes[cubedSum].push_back(i);
				sum_of_cubes[cubedSum].push_back(j);

				if(vectorHasRelativePrimes(sum_of_cubes[cubedSum])) {

					cout << "FOUND SOLUTION with " << sum_of_cubes[cubedSum].size()/2 << endl;
					cout << cubedSum << endl;
					printCubes(sum_of_cubes[cubedSum]);
					cout << "--------" << endl;
				}
			}

		}
	}
}


int main() {

	findSumOfCubes();

}
