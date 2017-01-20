#include <iostream>
#include <vector>
using namespace std;

unsigned long long
choose(unsigned long long n, unsigned long long k) {
    if (k > n) {
        return 0;
    }
    unsigned long long r = 1;
    for (unsigned long long d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    return r;
}
 
// A utility function to print an array p[] of size 'n'
void printArray(vector<int>& p, int n)
{
    for (int i = 0; i < n; i++)
       cout << p[i] << " ";
    cout << endl;
}

void print2dVec(vector< vector<int> > & vec) {
    for(size_t i = 0; i < vec.size(); i++) {
        for(size_t j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
}

void cleanVec(vector< vector<int> > & vec) {
    for(size_t i = 0; i < vec.size(); i++) {
        int count = 0;
        while(vec[i][count] != 0 && count < vec[i].size()) {
            count++;
        }
        vec[i].resize(count);
    }
}

vector< vector<int> > printAllUniqueParts(int n)
{
    vector<int> p(n); // An array to store a partition
    int k = 0;  // Index of last element in a partition
    p[k] = n;  // Initialize first partition as number itself

    vector< vector<int> > solution;
 
    // This loop first prints current partition, then generates next
    // partition. The loop stops when the current partition has all 1s
    while (true)
    {
        // print current partition
        //printArray(p, k+1);

        solution.push_back(p);
 
        // Generate next partition
 
        // Find the rightmost non-one value in p[]. Also, update the
        // rem_val so that we know how much value can be accommodated
        int rem_val = 0;
        while (k >= 0 && p[k] == 1)
        {
            rem_val += p[k];
            k--;
        }
 
        // if k < 0, all the values are 1 so there are no more partitions
        if (k < 0) {
            cleanVec(solution);
            return solution;
        }
 
        // Decrease the p[k] found above and adjust the rem_val
        p[k]--;
        rem_val++;
 
 
        // If rem_val is more, then the sorted order is violeted.  Divide
        // rem_val in differnt values of size p[k] and copy these values at
        // different positions after p[k]
        while (rem_val > p[k])
        {
            p[k+1] = p[k];
            rem_val = rem_val - p[k];
            k++;
        }
 
        // Copy rem_val to next position and increment position
        p[k+1] = rem_val;
        k++;
    }
}

int main() {
    vector< vector<int> > sol = printAllUniqueParts(41);
    print2dVec(sol);

}



