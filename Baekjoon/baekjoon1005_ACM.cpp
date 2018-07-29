#include <iostream>
#include <algorithm>

using namespace std;
int dp[1001];

int findcost(bool(*building)[1001], int dest, int *builcost, int builnumber) {
	if (dp[dest] > -1) {
		return dp[dest];
	}
	int result = 0;
	for (int i = 1; i <= builnumber; i++) {
		if (building[i][dest] == 1) {
			result = max(result, findcost(building,i,builcost,builnumber));
		}
	}
	return dp[dest] =(result + builcost[dest]);
}
int main() {
	int cases;
	cin >> cases;

	for (int i = 0; i < cases; i++) {
		bool building[1001][1001];
		int builcost[1001];
		int builA, builB, dest;
		fill(building[0], building[0] + 1002001, false);
		fill(dp, dp + 1001, -1);

		int builnumber, rulenumber;
		cin >> builnumber >> rulenumber;
		for (int k = 1; k <= builnumber; k++) {
			cin >> builcost[k];
		}
		for (int k = 0; k < rulenumber; k++) {
			cin >> builA >> builB;
			building[builA][builB] = 1;
		}
		cin >> dest;
		cout << findcost(building, dest, builcost, builnumber) << endl;
	}
}