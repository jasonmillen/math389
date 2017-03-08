#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector< vector<int> > part5 = { { 5 }, { 4, 1 }, { 3, 2 }, { 3, 1, 1 }, { 2, 2, 1 }, { 2, 1, 1, 1 }, { 1, 1, 1, 1, 1 } };

void printPartitonSize(int num, vector< vector<int> > & partitions) {
	cout << "num: " << num << ", size: " << partitions.size() << endl;
}

void print2dVec(vector< vector<int> > & v) {
	for(size_t i = 0; i < v.size(); i++) {
		for(size_t j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void print2dVecToStore(vector< vector<int> > & v) {

	cout << "{ ";

	for(size_t i = 0; i < v.size() - 1; i++) {
		cout << "{ ";
		for(size_t j = 0; j < v[i].size() - 1; j++) {
			cout << v[i][j] << ", ";
		}
		cout << v[i][v[i].size() - 1];
		cout << " }, ";
	}

	// last partition
	cout << "{ ";
	for(size_t i = 0; i < v[v.size() - 1].size() - 1; i++) {
		cout << v[v.size() - 1][i] << ", ";
	}
	cout << v[v.size() - 1][v[v.size() - 1].size() - 1];
	cout << " }";
	cout << " }";
	cout << endl;
}

void writePartitionsToFile(vector< vector<int> > & partitions) {
	ofstream outputFile("partition.txt");


}

vector< vector<int> > nextPartition(vector< vector<int> > & curPartition) {
	vector< vector<int> > solution;

	// holds a partition
	vector<int> p;

	// handle base case
	p.push_back(curPartition[0][0] + 1);
	solution.push_back(p);
	p.clear();
	p.push_back(curPartition[0][0]);
	p.push_back(1);
	solution.push_back(p);

	for(size_t i = 1; i < curPartition.size(); i++) {

		int size = curPartition[i].size();

		if(curPartition[i][size - 1] + 1 <= curPartition[i][size - 2]) {
			// can generate 2 new
			p = curPartition[i];
			p[size - 1] += 1;
			solution.push_back(p);
			p[size - 1] -= 1;
			p.push_back(1);
			solution.push_back(p);
		}
		else {
			// can generate 1 new
			p = curPartition[i];
			p.push_back(1);
			solution.push_back(p);

		}


	}

	return solution;

}

vector< vector<int> > sixtyPartitions;



int main() {

	vector< vector<int> > partitions;

	// initialize with partition for 2
	// vector<int> v;
	// v.push_back(2);
	// partitions.push_back(v);
	// v.clear();

	// v.push_back(1);
	// v.push_back(1);
	// partitions.push_back(v);


	partitions = part5;

	for(int i = 6; i <= 30; i++) {
		partitions = nextPartition(partitions);
		printPartitonSize(i, partitions);
	}

	print2dVecToStore(partitions);


	// vector< vector<int> > blah = { {1, 2, 3}, {2, 4} };

	// print2dVec(blah);

	
}


