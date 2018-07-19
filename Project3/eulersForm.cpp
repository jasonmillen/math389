#include <iostream>
#include <vector>

using namespace std;

void formula(long long a, long long b) {
	long long x1 = 1 - (a - 3*b)*(a*a + 3*b*b);
	long long x2 = (a + 3*b)*(a*a + 3*b*b) - 1;
	long long  x3 = (a + 3*b) - (a*a + 3*b*b)*(a*a + 3*b*b);
	long long  x4 = (a*a + 3*b*b)*(a*a + 3*b*b) - (a - 3*b);

	cout << x1 * x2 << endl;
	cout << x1 << ", " << x2 << " | " << x3 << ", " << x4 << endl;
}

int main() {

	while(true) {
		cout << "enter a, b\n";
		long long a, b;
		cin >> a >> b;

		cout << endl;
		formula(a, b);
		cout << endl;
	}

	return 0;
}

/*
-examples of primitive cubes and their multiples
-examples of sister cubes
*/