#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

const int MOD = 5;
const int DEG = 200;

vector<double> numIrrFoundMod3 = {0, 3, 3, 8, 18, 48, -1, -1 , -1, -1, -1, -1, -1, -1, -1, -1};



// A utility function to print an array p[] of size 'n'
void printArray(int p[], int n)
{
    for (int i = 0; i < n; i++)
       cout << p[i] << " ";
    cout << endl;
}

vector< vector<int> > printAllUniquePartsx(int n)
{
    vector< vector<int> > solution;

    int p[n]; // An array to store a partition
    int k = 0;  // Index of last element in a partition
    p[k] = n;  // Initialize first partition as number itself
 
    // This loop first prints current partition, then generates next
    // partition. The loop stops when the current partition has all 1s
    while (true)
    {
        // print current partition
        //printArray(p, k+1);
        vector<int> v;
        for(int i = 0; i < k + 1; i++) {
            v.push_back(p[i]);
        }
        solution.push_back(v);
        
 
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
        if (k < 0)  return solution;
 
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

void printVec(vector<int> & v) {
    for(size_t i = 0; i < v.size() - 1; i++) {
        cout << v[i] << " ";
    }
    cout << v[v.size() - 1] << endl;
}

int numDeg1MonicIrr(int mod) {
    return mod;
}

double
choose(double n, double k) {
    if (k > n) {
        return 0;
    }
    double r = 1;
    for (double d = 1; d <= k; ++d) {
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

// helper for finding partitions
void cleanVec(vector< vector<int> > & vec) {
    for(size_t i = 0; i < vec.size(); i++) {
        int count = 0;
        while(vec[i][count] != 0 && count < vec[i].size()) {
            count++;
        }
        vec[i].resize(count);
    }
}

// find partitions
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

double multiChoose(double n, double k) {
    return choose(n + k - 1, k);
}

// mod specific
double numberFromPartiton(vector<int> & partition, vector<double> & prevCalcNumIrr) {

    //printVec(partition);

    int curCount = 1;
    int curNum = partition[0];
    double total = 1;
    for(int i = 1; i < partition.size(); i++) {
        if(partition[i] != curNum) {
            double n = prevCalcNumIrr[curNum];
            double k = curCount;
            total *= multiChoose(n, k);

            curCount = 1;
            curNum = partition[i];
        }
        else {
            curCount++;
        }
    }

    // do last partition
    double n = prevCalcNumIrr[curNum];
    double k = curCount;
    total *= multiChoose(n, k);

    //cout << "total: " << total << endl;
    return total;
}

double findNumIrr(int deg, int mod) {

    vector<double> prevCalcNumIrr;
    prevCalcNumIrr.push_back(0); // dummy value to keep indexes 1 indexed
    prevCalcNumIrr.push_back(numDeg1MonicIrr(mod));

    int curDegree = 2;
    while(curDegree <= deg) {
        //if(numIrrFoundMod[mod][curDegree] == -1) {
        if(true) {
            vector< vector<int> > partitions = printAllUniquePartsx(curDegree);

            double total = 0;

            // start at 1 to avoid irreducible partition (first partition)
            for(size_t i = 1; i < partitions.size(); i++) {
                total +=  numberFromPartiton(partitions[i], prevCalcNumIrr);
            }
            double totalPol = pow(mod, curDegree);
            prevCalcNumIrr.push_back(totalPol - total);  
        }
        else {
            prevCalcNumIrr.push_back(numIrrFoundMod3[curDegree]);
        }

        cout << "num irr with mod " << mod << " at degree " << curDegree << " is " << prevCalcNumIrr[curDegree] << endl;

        curDegree++;
    }

    return prevCalcNumIrr[deg];


}



int main() {

    //vector< vector<int> > partitions = printAllUniquePartsx(70);
    //print2dVec(partitions);

    findNumIrr(DEG, MOD);

    // double i = 18446744073709551615;
    // cout << i << endl;
    // cout << i + 1 << endl;

}



