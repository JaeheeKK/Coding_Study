#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

vector <pair<int, int>> chicks;
vector <pair<int, int>> houses;
vector <int> permu;

int map[50][50];

int chicken_distance(int maps, int chicken) {
	for (int a = 0; a < chicken; a++) {
		permu.push_back(1);
	}
	for (int b = 0; b < (chicks.size() - chicken); b++) {
		permu.push_back(0);
	}
	sort(permu.begin(), permu.end());
	int min_result = (maps + maps + 1)*houses.size();

	do {
		int temp_result = 0;
		for (int d = 0; d < houses.size(); d++) {
			int min = maps + maps + 1;
			for (int c = 0; c < permu.size(); c++) {
				if (permu[c] == 1) {
					int temp = abs(houses[d].first - chicks[c].first) + abs(houses[d].second - chicks[c].second);
					if (min > temp) {
						min = temp;
					}
				}
			}
			temp_result += min;
		}
		if (min_result > temp_result) {
			min_result = temp_result;
		}
	} while (next_permutation(permu.begin(), permu.end()));
	
	return min_result;
}
int main() {
	int maps, chicken;

	cin >> maps >> chicken;

	for (int i = 0; i < maps; i++) {
		for (int k = 0; k < maps; k++) {
			cin >> map[i][k];
			if (map[i][k] == 2) {
				chicks.push_back(make_pair(i, k));
			}
			else if (map[i][k] == 1) {
				houses.push_back(make_pair(i, k));
			}
		}
	}
	cout << chicken_distance(maps, chicken) << endl;
}