#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


struct QuadPoly {
	int a0;
	int a1;
	int a2;

	QuadPoly(int a0_in, int a1_in, int a2_in): a0(a0_in), a1(a1_in), a2(a2_in) {}

	void print() {
		bool firstPrinted = false;

		if(a2 != 0) {
			if(a2 != 1) {
				cout << a2;
			}
			cout << "x^2";
			firstPrinted = true;
		}
		if(a1 != 0) {
			if(firstPrinted) {
				cout << " + ";
			}
			if(a1 != 1) {
				cout << a1;
			}
			cout << "x";
			firstPrinted = true;
		}
		if(a0 != 0) {
			if(firstPrinted) {
				cout << " + ";
			}
			cout << a0;
		}
	}
};

struct LinePoly {
	int a0;
	int a1;

	LinePoly(int a0_in, int a1_in): a0(a0_in), a1(a1_in) {}

	void print() {
		bool firstPrinted = false;

		if(a1 != 0) {
			if(a1 != 1) {
				cout << a1;
			}
			cout << "x";
			firstPrinted = true;
		}
		if(a0 != 0) {
			if(firstPrinted) {
				cout << " + ";
			}
			cout << a0;
		}
	}
};

int modNum(int num, int mod) {
	if(num < 0) {
		while(num < 0) {
			num += mod;
		}
	}
	else if(num >= mod) {
		while(num >= mod) {
			num -= mod;
		}
	}

	return num;
}

QuadPoly mult(LinePoly lp1, LinePoly lp2, int mod) {
	int a2 = lp1.a1 * lp2.a1;
	int a1 = (lp1.a0 * lp2.a1) + (lp1.a1 * lp2.a0);
	int a0 = lp1.a0 * lp2.a0;

	a2 = modNum(a2, mod);
	a1 = modNum(a1, mod);
	a0 = modNum(a0, mod);

	return QuadPoly(a0, a1, a2);
}

void printPair(LinePoly lp1, LinePoly lp2) {
	cout << "(";
	lp1.print();
	cout << "), (";
	lp2.print();
	cout << ")";
}


int findFactors(QuadPoly qp, int mod) {
	int count = 0;

	for(int i = 0; i < mod; i++) {
		for(int j = 0; j < mod; j++) {
			LinePoly lp1(j, i);

			for(int k = i; k < mod; k++) {
				for(int l = j; l < mod; l++) {
					LinePoly lp2(l, k);

					QuadPoly qpAns = mult(lp1, lp2, mod);
					if(qpAns.a0 == qp.a0 && qpAns.a1 == qp.a1 && qpAns.a2 == qp.a2) {
						printPair(lp1, lp2);
						cout << "\n";
						count++;

						l = mod;
						k = mod;
						j = mod;
						i = mod;
					}
				}
			}
		}
	}

	if(count == 0) {
		cout << "irreducible\n";
	}
	return count;
}

void findQuadFactors(int mod) {

	int numIrreducible = 0;

	for(int i = 0; i < mod; i++) {
		for(int j = 0; j < mod; j++) {
			QuadPoly qp(j, i, 1);
			qp.print();
			cout << " >> factors\n";
			int count = findFactors(qp, mod);
			if(count == 0) {
				numIrreducible++;
			}
			cout << "-------\n\n";
		}
	}
	
	cout << "mod is " << mod << ", squared is " << mod * mod << endl;
	int total = 0;
	for(int i = mod; i >= 2; i--) {
		cout << i << "+";
		total += i;
	}
	total += 1;
	cout << 1 << " = " << total << endl;
	cout << mod * mod << " - " << total << " = " << ((mod * mod) - total) << endl;
	cout << "numIrreducible is " << numIrreducible << endl;
}

int main() {

	int mod = 11;

	findQuadFactors(mod);

	return 0;

}