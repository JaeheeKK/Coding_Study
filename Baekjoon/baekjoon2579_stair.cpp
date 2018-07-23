#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int stairs;
	cin >> stairs;
	int *score = new int[stairs+1];
	int result[301][2] = { 0, };


	for (int i = 1; i <= stairs; i++) {
		cin >> score[i];
	}
	result[1][0] = score[1];
	result[1][1] = score[1];
	result[2][0] = score[1] + score[2];
	result[2][1] = score[2];
	for (int k = 3; k <= stairs; k++) {
		result[k][0] = result[k - 1][1] + score[k];
		result[k][1] = max(result[k - 2][0], result[k - 2][1]) + score[k];
	}
	cout << max(result[stairs][0],result[stairs][1]) << endl;
}