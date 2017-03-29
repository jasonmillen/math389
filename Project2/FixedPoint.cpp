#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

// use str.find() to see if string is contained in another string

vector<string> rules = {"0", "1", "00", "01", "10", "11", "000", "001", "010", "011", "100", "101", "110", "111"};
vector<string> seeds = {"0", "1", "00", "01", "10", "11", "000", "001", "010", "011", "100", "101", "110", "111"};

vector<string> rulesTrivial = {"0", "1", "01", "10", "001", "010", "011", "100", "101", "110"};
vector<string> seedsTrivial = {"0", "1", "01", "10", "001", "010", "011", "100", "101", "110"};


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


bool isSameCharTrivial(unordered_map<char, string> & rule, string seed) {
	char rule0char = rule['0'][0];
	return true;
}

bool isTrivial(unordered_map<char, string> & rule, string seed) {
	if(rule['0'] == rule['1'] && rule['0'] == seed) {
		return true;
	}
	if(rule['0'] == "0" && rule['1'] == "1") {
		// identity
		return true;
	}
	if(rule['0'] == "0" && seed == "0") {
		// half identity
		return true;
	}
	if(rule['1'] == "1" && seed == "1") {
		// half identity
		return true;
	}
	return false;
}

void findNonTrivialFixedPoints() {
	unordered_map<char, string> rule;
	string seed;

	for(int i = 0; i < rulesTrivial.size(); i++) {
		for(int j = 0; j < rulesTrivial.size(); j++) {
			for(int k = 0; k < seedsTrivial.size(); k++) {

				rule['0'] = rulesTrivial[i];
				rule['1'] = rulesTrivial[j];
				seed = seedsTrivial[k];

				if(testFixedPoint(rule, seed, 15) && !isTrivial(rule, seed)) {
					cout << "0 -> " << rule['0'] << endl;
					cout << "1 -> " << rule['1'] << endl;
					cout << "seed: " << seed << endl;
					cout << "--------" << endl;
				}

			}
		}
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

				cout << "0 -> " << rule['0'] << endl;
				cout << "1 -> " << rule['1'] << endl;
				cout << "seed: " << seed << endl;

				if(testFixedPoint(rule, seed, 5)) {
					cout << "YES" << endl;
				}
				else {
					
					seed = generateNewSeq(rule, seed);

					if(testFixedPoint(rule, seed, 5)) {
						cout << "YES - non strict" << endl;
					}
					else {
						cout << "NO" << endl;
					}
				}
				cout << "----------" << endl;

			}
		}
	}
}


void testSeedAsRule() {
	unordered_map<char, string> rule;
	string seed;

	for(int i = 0; i < rules.size(); i++) {
		for(int j = 0; j < rules.size(); j++) {

			rule['0'] = rules[i];
			rule['1'] = rules[j];
			seed = rule['0'];

			if(!testFixedPoint(rule, seed, 15)) {
				cout << "0 -> " << rule['0'] << endl;
				cout << "1 -> " << rule['1'] << endl;
				cout << "seed: " << seed << endl;
				cout << "--------" << endl;
			}

			seed = rule['1'];

			if(!testFixedPoint(rule, seed, 15)) {
				cout << "0 -> " << rule['0'] << endl;
				cout << "1 -> " << rule['1'] << endl;
				cout << "seed: " << seed << endl;
				cout << "--------" << endl;
			}

		}
	}
}

int main() {

	findFixedPoints();
	return 0;

	// printRules(3, "");
	
	unordered_map<char, string> rule;
	rule['0'] = "0";
	rule['1'] = "011";

	string seed = "1";

	string seq = seed;
	for(int i = 0; i < 10; i++) {
		cout << seq << endl;
		seq = generateNewSeq(rule, seq);
	}


	// printSequences(rule, seed, 15);
	// if(testFixedPoint(rule, seed, 15)) {
	// 	cout << "yes" << endl;
	// }
	// else {
	// 	cout << "no" << endl;
	// }

}