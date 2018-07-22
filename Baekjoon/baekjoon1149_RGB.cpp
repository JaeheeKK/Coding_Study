#include<iostream>
#include<algorithm>

using namespace std;

void min_money(int (*money)[3], int houses) {
	int result[1000][3] = { 0, };
	int answer;

	for (int k = 1; k < houses; k++) {
		money[k][0] += min(money[k - 1][1], money[k - 1][2]);
		money[k][1] += min(money[k - 1][0], money[k - 1][2]);
		money[k][2] += min(money[k - 1][0], money[k - 1][1]);
	}
	answer = min(money[houses - 1][0], money[houses - 1][1]);
	answer = min(answer, money[houses - 1][2]);

	cout << answer << endl;
}
int main() {
	int houses;
	cin >> houses;
	int money[1000][3];

	for (int a = 0; a < houses; a++) {
		for (int b = 0; b < 3; b++) {
			cin >> money[a][b];
		}
	}
	min_money(money, houses);
}