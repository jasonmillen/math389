#include <iostream>
#include <fstream>

using namespace std;

void printAllUniqueParts(int n) {

    ofstream outputFile("partition.txt");

    int p[n]; // An array to store a partition
    int k = 0;  // Index of last element in a partition
    p[k] = n;  // Initialize first partition as number itself
 
    // This loop first prints current partition, then generates next
    // partition. The loop stops when the current partition has all 1s
    while (true)
    {
        // print current partition
        for(int i = 0; i < k + 1; i++) {
            outputFile << p[i];
        }
        outputFile << endl;
        
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
        if (k < 0)  return;
 
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
    printAllUniqueParts(5);
}