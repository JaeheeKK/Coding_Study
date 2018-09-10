#include <iostream>

using namespace std;

int map[101][101];
int check[101][101];

int cal_slope_row(int sizes, int length, int xy) {
	int start_y = 0;
	int results = 0;
	int next_y;
	while (start_y < (sizes-1)) {
		next_y = start_y + 1;
		while (map[xy][start_y] == map[xy][next_y]) {
			if (next_y == (sizes - 1)) {
				results = 1;
				return results;
			}
			start_y += 1;
			next_y += 1;
		}
		if (map[xy][start_y] == (map[xy][next_y] + 1)) {
			for (int x = 0; x < length - 1; x++) {
				if (next_y >= (sizes - 1)) {
					return results;
				}
				if ((!check[xy][next_y]&& !check[xy][next_y+1]) && map[xy][next_y] == map[xy][next_y + 1]) {
					check[xy][next_y] = 1;
					next_y += 1;
				}
				else {
					return results;
				}
			}
			if (check[xy][next_y]) {
				return results;
			}
			check[xy][next_y] = 1;
			start_y = next_y;
		}
		else if (map[xy][start_y] == (map[xy][next_y] - 1)) {
			for (int h = 0; h < length - 1; h++) {
				if (start_y < 1) {
					return results;
				}
				if ((!check[xy][start_y] && !check[xy][start_y -1]) && map[xy][start_y] == map[xy][start_y - 1]) {
					check[xy][start_y] = 1;
					start_y -= 1;
				}
				else {
					return results;
				}
			}
			if (check[xy][start_y]) {
				return results;
			}
			check[xy][start_y] = 1;
			start_y = next_y;
		}
		else {
			return results;
		}
	}
	results = 1;
	return results;
}
int cal_slope_column(int sizes, int length, int xy) {
	int start_x = 0;
	int results = 0;
	int next_x;
	while (start_x < (sizes - 1)) {
		next_x = start_x + 1;
		while (map[start_x][xy] == map[next_x][xy]) {
			if (next_x == (sizes - 1)) {
				results = 1;
				return results;
			}
			start_x += 1;
			next_x += 1;
		}
		if (map[start_x][xy] == (map[next_x][xy] + 1)) {
			for (int x = 0; x < length - 1; x++) {
				if (next_x >= (sizes - 1)) {
					return results;
				}
				if ((!check[next_x][xy] && !check[next_x+1][xy]) && map[next_x][xy] == map[next_x+1][xy]) {
					check[next_x][xy] = 1;
					next_x += 1;
				}
				else {
					return results;
				}
			}
			if (check[next_x][xy]) {
				return results;
			}
			check[next_x][xy] = 1;
			start_x = next_x;
		}
		else if (map[start_x][xy] == (map[next_x][xy] - 1)) {
			for (int h = 0; h < length - 1; h++) {
				if (start_x < 1) {
					return results;
				}
				if ((!check[start_x][xy] && !check[start_x-1][xy]) && map[start_x][xy] == map[start_x-1][xy]) {
					check[start_x][xy] = 1;
					start_x -= 1;
				}
				else {
					return results;
				}
			}
			if (check[start_x][xy]) {
				return results;
			}
			check[start_x][xy] = 1;
			start_x = next_x;
		}
		else {
			return results;
		}
	}
	results = 1;
	return results;
}
int main() {
	int sizes, length, answer=0;
	cin >> sizes >> length;

	for (int i = 0; i < sizes; i++) {
		for (int j = 0; j < sizes; j++) {
			cin >> map[i][j];
		}
	}
	for (int a = 0; a < sizes; a++) {
		answer += cal_slope_row(sizes, length, a);
		for (int b = 0; b < sizes; b++) {
			check[a][b] = 0;
		}
	}
	for (int q = 0; q < sizes; q++) {
		answer += cal_slope_column(sizes, length, q);
		for (int t = 0; t < sizes; t++) {
			check[t][q] = 0;
		}
	}
	cout << answer << endl;
}