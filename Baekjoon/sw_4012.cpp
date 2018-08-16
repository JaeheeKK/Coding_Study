/*#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int foods[16][16];

int food_cook(int food) {
	vector <int> permu;
	int min_food=200000;
	for (int k = 0; k < food; k++) {
		if (k < (food / 2)) {
			permu.push_back(1);
		}
		else {
			permu.push_back(0);
		}
	}
		sort(permu.begin(), permu.end());
		do {
			int food_A = 0, food_B = 0;
			for (int s = 0; s < permu.size(); s++) {
				if (permu[s] == 1) {
					for (int g = s + 1; g < permu.size(); g++) {
						if(permu[g] == 1){
							food_A = food_A + foods[s][g] + foods[g][s];
						}
					}
				}
				else if (permu[s] == 0) {
					for (int p = s + 1; p < permu.size(); p++) {
						if (permu[p] == 0) {
							food_B= food_B + foods[s][p] + foods[p][s];
						}
					}
				}
			}
			int food_result = abs(food_A - food_B);
			if (min_food > food_result) {
				min_food = food_result;
			}
		} while (next_permutation(permu.begin(), permu.end()));
		return min_food;
}
int main() {
	int cases;
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		int food;
		cin >> food;
		for (int a = 0; a < food; a++) {
			for (int b = 0; b < food; b++) {
				cin >> foods[a][b];
			}
		}
		cout << '#'<<i+1<<" "<<food_cook(food) << endl;
	}
}*/