// Program to print all prime factors
#include <math.h>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


void pretty_print(const vector<int>& v) {
  static int count = 0;
  cout << "combination no " << (++count) << ": [ ";
  for (int i = 0; i < v.size(); ++i) { cout << v[i] << " "; }
  cout << "] " << endl;
}

template <typename T>
void print2dVec(vector< vector<T> > & v) {
    for(size_t i = 0; i < v.size(); i++) {
        for(size_t j = 0; j < v[i].size(); j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void combinations(int offset, int k, vector<int> & unique_prime_factors, 
    vector<int> & combination, vector< vector<int> > & comb_solution) {

  if (k == 0) {
    //pretty_print(combination);
    comb_solution.push_back(combination);
    return;
  }
  for (int i = offset; i <= unique_prime_factors.size() - k; ++i) {
    combination.push_back(unique_prime_factors[i]);
    combinations(i+1, k-1, unique_prime_factors, combination, comb_solution);
    combination.pop_back();
  }
}


void printFactors(unordered_map<int, int> & m) {

    int total = 1;

    for(auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " - " << it->second << endl;

        for(int i = 0; i < it->second; i++) {
            total *= it->first;
        }
    }

    cout << "total: " << total << endl;
}
 
// A function to print all prime factors of a given number n
unordered_map<int, int> primeFactors(int n, vector<int> & unique_prime_factors) {

    unordered_map<int, int> prime_factors;

    // Print the number of 2s that divide n
    while (n%2 == 0) {

        if(prime_factors.find(2) == prime_factors.end()) {
            prime_factors[2] = 1;
            unique_prime_factors.push_back(2);
        }
        else {
            prime_factors[2]++;
        }

        n = n/2;
    }
 
    // n must be odd at this point.  So we can skip one element (Note i = i +2)
    for (int i = 3; i <= sqrt(n); i = i+2) {

        // While i divides n, print i and divide n
        while (n%i == 0) {

            if(prime_factors.find(i) == prime_factors.end()) {
                prime_factors[i] = 1;
                unique_prime_factors.push_back(i);
            }
            else {
                prime_factors[i]++;
            }

            n = n/i;
        }
    }
 
    // This condition is to handle the case whien n is a prime number
    // greater than 2
    if (n > 2) {

        prime_factors[n] = 1;
        unique_prime_factors.push_back(n);
    }

    return prime_factors;
}

int w_val(unordered_map<int, int> & prime_factors) {

    int w = 1;

    for(auto it = prime_factors.begin(); it != prime_factors.end(); it++) {
        if(it->second > 1) {
            w *= pow(it->first, it->second - 1);
        }
    }

    return w;
}

double calcForKValue(int P, int k, int s, int w, vector< vector<int> > & comb_solution) {

    double solution = 0;

    if(k > 0) {
        for(size_t i = 0; i < comb_solution.size(); i++) {
            int exponent = w;
            for(size_t j = 0; j < comb_solution[i].size(); j++) {
                exponent *= comb_solution[i][j];
            }

            solution += pow(P, exponent);
        }
    }
    else {
        solution = pow(P, w);
    }


    if((k + s) % 2 != 0) {
        solution *= -1;
    }

    return solution;
}

double sukisForm(int P, int n) {

    double solution = 0;

    vector<int> unique_prime_factors;
    unordered_map<int, int> prime_factors = primeFactors(n, unique_prime_factors);

    int w = w_val(prime_factors);
    int s = unique_prime_factors.size();

    vector<int> combination;
    vector< vector<int> > comb_solution;

    // k value of 0
    solution += calcForKValue(P, 0, s, w, comb_solution);

    for(size_t i = 1; i <= unique_prime_factors.size(); i++) {
        combinations(0, i, unique_prime_factors, combination, comb_solution);

        solution += calcForKValue(P, i, s, w, comb_solution);

        combination.clear();
        comb_solution.clear();
    }

    return solution / n;
}
 
/* Driver program to test above function */
int main() {

    int P = 3;

    for(int i = 2; i <= 100; i++) {
        cout << i << ": " << sukisForm(P, i) << endl;
    }

    return 0;
}



