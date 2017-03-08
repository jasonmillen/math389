#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

// use str.find() to see if string is contained in another string

vector<string> rules = {"0", "1", "00", "01", "10", "11", "000", "001", "010", "011", "100", "101", "110", "111"};
vector<string> seeds = {"0", "1", "00", "01", "10", "11", "000", "001", "010", "011", "100", "101", "110", "111"};

void printRules(int size, string cur) {
	if(cur.size() == size) {
		cout << cur << endl;
	}
	else {
		printRules(size, cur + "0");
		printRules(size, cur + "1");
	}

}

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

void findFixedPoints() {
	unordered_map<char, string> rule;
	string seed;

	for(int i = 0; i < rules.size(); i++) {
		for(int j = 0; j < rules.size(); j++) {
			for(int k = 0; k < seeds.size(); k++) {

				rule['0'] = rules[i];
				rule['1'] = rules[j];
				seed = seeds[k];

				if(testFixedPoint(rule, seed, 15)) {
					cout << "0 -> " << rule['0'] << endl;
					cout << "1 -> " << rule['1'] << endl;
					cout << "seed: " << seed << endl;
					cout << "--------" << endl;
				}

			}
		}
	}
}


int main() {

	findFixedPoints();
	return 0;

	printRules(3, "");
	
	unordered_map<char, string> rule;
	rule['0'] = "01";
	rule['1'] = "10";

	string seed = "1";


	printSequences(rule, seed, 15);
	if(testFixedPoint(rule, seed, 15)) {
		cout << "yes" << endl;
	}
	else {
		cout << "no" << endl;
	}

}