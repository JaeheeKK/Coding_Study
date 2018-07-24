#include <iostream>

using namespace std;

int pado[101] = { 0, };

int padovan(int number) {
	
	for (int k = 5; k < number; k++) {
		pado[k] = pado[k - 1] + pado[k - 5];
	}
	return pado[number-1];
}

int main() {
	int cases;
	cin >> cases;
	pado[0] = 1;
	pado[1] = 1;
	pado[2] = 1;
	pado[3] = 2;
	pado[4] = 2;

	for (int i = 0; i < cases; i++) {
		int number;
		cin >> number;
		cout << padovan(number) << endl;
	}
}