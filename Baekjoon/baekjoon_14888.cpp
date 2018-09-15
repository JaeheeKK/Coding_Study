#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int number[11];
int minn = 1000000001;
int maxx = -1000000001;

vector <int> calc;

void cal_number(int add, int subt, int mult, int divid) {
	do {
		int result = number[0];
		for (int j = 0; j < divid; j++) {
			if (calc[j] < add) {
				result += number[j + 1];
			}
			else if (calc[j] < subt) {
				result -= number[j + 1];
			}
			else if (calc[j] < mult) {
				result *= number[j + 1];
			}
			else if (calc[j] < divid) {
				result /= number[j + 1];
			}
		}
		if (result < minn) {
			minn = result;
		}
		if (result > maxx) {
			maxx = result;
		}
	} while (next_permutation(calc.begin(), calc.end()));
}

int main() {
	int how_many,add,subt,mult,divid;
	cin >> how_many;

	for (int i = 0; i < how_many; i++) {
		cin >> number[i];
	}

	cin >> add >> subt >> mult >> divid;
	subt += add;
	mult += subt;
	divid += mult;

	for (int a = 0; a < add; a++) {
		calc.push_back(a);
	}
	for (int b = add; b < subt; b++) {
		calc.push_back(b);
	}
	for (int c = subt; c < mult; c++) {
		calc.push_back(c);
	}
	for (int d = mult; d < divid; d++) {
		calc.push_back(d);
	}
	cal_number(add, subt, mult, divid);

	cout << maxx << endl<<minn << endl;
}