#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

// use str.find() to see if string is contained in another string

string generateNewSeq(unordered_map<char, string> & rule, string & cur) {
	string newSeq;
	for(int i = 0; i < cur.size(); i++) {
		newSeq += rule[cur[i]];
	}
	return newSeq;
}

// checks if b starts with a
bool startsWith(string a, string b) {
	if(a.size() > b.size()) {
		return false;
	}

	return (b.substr(0, a.size()) == a);
}

bool testFixedPoint(unordered_map<char, string> & rule, string seed, int numIter) {
	string cur = seed;
	string prev = cur;

	for(int i = 0; i < numIter; i++) {
		//cout << cur << endl;
		cur = generateNewSeq(rule, cur);

		if(!startsWith(prev, cur)) {
			return false;
		}
	}

	return true;
}

void printSequences(unordered_map<char, string> & rule, string seed, int numIter) {
	string cur = seed;
	for(int i = 0; i < numIter; i++) {
		cout << cur << endl;
		cur = generateNewSeq(rule, cur);
	}
}


int main() {
	
	unordered_map<char, string> rule;
	rule['0'] = "01";
	rule['1'] = "10";

	string seed = "0";


	printSequences(rule, seed, 30);
	// if(testFixedPoint(rule, seed, 100)) {
	// 	cout << "yes" << endl;
	// }
	// else {
	// 	cout << "no" << endl;
	// }

}