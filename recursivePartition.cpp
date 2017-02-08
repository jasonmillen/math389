#include <iostream>
#include <vector>

using namespace std;

void print2dVec(vector< vector<int> > & v) {
	cout << "size: " << v.size() << endl;
	return;

	for(size_t i = 0; i < v.size(); i++) {
		for(size_t j = 0; j < v[i].size(); j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
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



int main() {

	vector< vector<int> > partitions;

	vector<int> v;
	v.push_back(2);
	partitions.push_back(v);
	v.clear();

	v.push_back(1);
	v.push_back(1);
	partitions.push_back(v);

	//print2dVec(partitions);


	for(int i = 0; i < 60; i++) {
		partitions = nextPartition(partitions);
		print2dVec(partitions);
	}



}


