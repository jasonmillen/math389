#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <unordered_set>

using namespace std;

unsigned long long gcd (unsigned long long a, unsigned long long b) {
  unsigned long long x;
  while (b) {
	  x = a % b;
	  a = b;
	  b = x;
  }
  return a;
}

long long cube(long long n) {
	return n * n * n;
}

bool isprime(int N){
    if(N<2 || (!(N&1) && N!=2))
        return false;
    for(int i=3; i*i<=N; i+=2){
        if(!(N%i))
            return false;
    }
    return true;
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

int abs(int n) {
	if(n < 0) {
		n = n * -1;
	}
	return n;
}

bool passesSukiTest(vector<int> & v) {
	if(v.size() != 4) {
		return true;
	}

	if(abs(v[0] - v[2]) == 1) {
		int diff = abs(v[1] - v[3]);
		return isprime(diff);

	}
	else if(abs(v[1] - v[2]) == 1) {
		int diff = abs(v[0] - v[3]);
		return isprime(diff);

	}
	else if(abs(v[0] - v[3]) == 1) {
		int diff = abs(v[1] - v[2]);
		return isprime(diff);

	}
	else if(abs(v[1] - v[3]) == 1) {
		int diff = abs(v[0] - v[2]);
		return isprime(diff);

	}

	return true;
}

bool hasSisterCubes(vector<int> & a, vector<int> & b) {
	if(a.size() != 4 || b.size() != 4) {
		return false;
	}

	unordered_set<int> s;

	for(size_t i = 0; i < a.size(); i++) {
		s.insert(a[i]);
	}

	int sisterCount = 0;
	for(size_t i = 0; i < b.size(); i++) {
		if(s.find(b[i]) != s.end()) {
			sisterCount++;
		}
	}

	return (sisterCount == 2);

}

void printSisterCubes(long long num, vector< vector<int> > & sisterCubes) {

	cout << "SISTER CUBES:\n";
	cout << num << endl;

	for(size_t i = 0; i < sisterCubes.size(); i++) {
		printCubes(sisterCubes[i]);
	}
}

void findSisterCubes(unordered_map<long long, vector<int> > & sum_of_cubes) {

	vector< vector<int> > sisterCubes;

	for(auto it = sum_of_cubes.begin(); it != sum_of_cubes.end(); it++) {
		

		if(it->second.size() >= 4) {
			sisterCubes.push_back(it->second);

			for(auto it2 = it; it2 != sum_of_cubes.end(); it2++) {
				if(hasSisterCubes(it->second, it2->second)) {
					sisterCubes.push_back(it2->second);
				}

			}

			// cout << endl << "current soluton:" << endl;
			// printCubes(it->second);
			// cout << endl;

			if(sisterCubes.size() > 1) {
				printSisterCubes(it-> first, sisterCubes);
				cout << endl;
			}

			sisterCubes.clear();

		}

	}
}

bool vectorHasOne(vector<int> & v) {
	for(int i = 0; i < v.size(); i++) {
		if(v[i] == 1) {
			return true;
		}
	}

	return false;
}

unordered_map<long long, vector<int> > findSumOfCubes() {
	//unordered_map<int, string> sum_of_cubes;

	unordered_map<long long, vector<int> > sum_of_cubes;

	for(int i = 0; i < 5000; i++) {
		for(int j = i; j < 5000; j++) {
			
			long long cubedSum = cube(i) + cube(j);
			
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

					// if(!passesSukiTest(sum_of_cubes[cubedSum])) {

					// 	cout << "FOUND SOLUTION with " << sum_of_cubes[cubedSum].size()/2 << endl;
					// 	cout << cubedSum << endl;
					// 	printCubes(sum_of_cubes[cubedSum]);
					// 	cout << "--------" << endl;

					// }

					if(vectorHasOne(sum_of_cubes[cubedSum])) {

						cout << "FOUND SOLUTION with " << sum_of_cubes[cubedSum].size()/2 << endl;
						cout << cubedSum << endl;
						printCubes(sum_of_cubes[cubedSum]);
						cout << "--------" << endl;

					}

					// cout << "FOUND SOLUTION with " << sum_of_cubes[cubedSum].size()/2 << endl;
					// cout << cubedSum << endl;
					// printCubes(sum_of_cubes[cubedSum]);
					// cout << "--------" << endl;


				}
			}

		}
	}

	return sum_of_cubes;
}


int main() {

	findSumOfCubes();


	//unordered_map<long long, vector<int> > sum_of_cubes = findSumOfCubes();

	//findSisterCubes(sum_of_cubes);

}
