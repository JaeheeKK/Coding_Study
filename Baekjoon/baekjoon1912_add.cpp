#include<iostream>
#include<algorithm>

using namespace std;

int findmax(int *number, int numb) {
	int *dp = new int[numb];
	dp[0] = number[0];
	int max = dp[0];
	for (int i = 1; i < numb; i++) {
		dp[i] = dp[i - 1] + number[i] < number[i] ? number[i] : dp[i - 1] + number[i];
		if (max < dp[i]) {
			max = dp[i];
		}
	}
	return max;
}
int main() {
	int numb;
	cin >> numb;

	int *number = new int[numb];
	for (int i = 0; i < numb; i++) {
		cin >> number[i];
	}
	cout << findmax(number, numb) << endl;
}