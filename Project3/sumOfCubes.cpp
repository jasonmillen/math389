#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int cube(int n) {
	return n * n * n;
}

string generateStringForm(int a, int b) {
	return to_string(a) + ", " + to_string(b);
}

void findSumOfCubes() {
	unordered_map<int, string> sum_of_cubes;

	for(int i = 0; i < 1000; i++) {
		for(int j = i; j < 1000; j++) {
			
			int cubedSum = cube(i) + cube(j);
			string s = generateStringForm(i, j);

			if(sum_of_cubes.find(cubedSum) == sum_of_cubes.end()) {
				sum_of_cubes[cubedSum] = s;
			}
			else {
				cout << "FOUND PAIR" << endl;
				cout << cubedSum << endl;
				cout << sum_of_cubes[cubedSum] << " -- " << s << endl;
				cout << "--------" << endl;
			}

		}
	}
}


int main() {

	findSumOfCubes();

}
