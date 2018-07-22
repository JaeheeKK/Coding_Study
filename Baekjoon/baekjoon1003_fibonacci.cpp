#include <iostream>

using namespace std;

void fibonacci(int number) {
	int result[41][2] = { 0, };
	result[0][0] = 1;
	result[1][1] = 1;

	for (int k = 2; k <= number; k++) {
		result[k][0] = result[k - 1][0] + result[k-2][0];
		result[k][1] = result[k - 1][1] + result[k - 2][1];
	}
	cout << result[number][0] << " " << result[number][1] << endl;
}
int main() {
	int cases;
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		int number;
		cin >> number;
		fibonacci(number);
	}
}