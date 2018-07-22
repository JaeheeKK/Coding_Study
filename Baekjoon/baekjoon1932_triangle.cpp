#include <iostream>
#include <algorithm>

using namespace std;
int main() {
	int triangle;
	cin >> triangle;

	int trinums = (triangle + 1)*(triangle) / 2;
	int check1 = trinums;
	int check2 = triangle - 1;
	int *tris = new int[trinums];

	for (int i = 0; i < trinums; i++) {
		cin >> tris[i];
	}
	for (int a = 1; a < triangle; a++) {
		for (int b = 1; b <= check2; b++) {
			tris[check1 - check2 - b - 1] += max(tris[check1 - b], tris[check1 - b - 1]);
		}
		check1 = check1 - check2 - 1;
		check2 -= 1;
	}
	cout << tris[0] << endl;
}