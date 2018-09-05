#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

int max_result = 0;
queue <int> scores;
vector<vector<int>> board;
stack<vector<vector<int>>> before;

void cal_dir(int sizes, int direct) {
	switch (direct) {
	case 0://up
		for (int c = 0; c < sizes; c++) {
			int next_x = 1;
			int x = 0;
			while (x < sizes) {//그 다음 비어있지 않은 걸 찾을 때까지
				if (board[x][c] != 0) {
					if (x == (sizes - 1)) {
						scores.push(board[x][c]);
						break;
					}
					while (board[next_x][c] == 0) {
						next_x += 1;
						if (next_x >= sizes) {
							scores.push(board[x][c]);
							x = sizes;
							break;
						}
					}
					if (next_x < sizes) {
						if (board[x][c] == board[next_x][c]) {
							scores.push(2 * board[x][c]);
							x = next_x + 1;
							next_x = x + 1;
						}
						else {
							scores.push(board[x][c]);
							x = next_x;
							next_x = x + 1;
						}
					}
				}
				else {
					x += 1;
					next_x += 1;
				}
			}
			for (int z = 0; z < sizes; z++) {
				if (scores.empty()) {
					board[z][c] = 0;
				}
				else {
					board[z][c] = scores.front();
					scores.pop();
				}
			}
		}
		break;
	case 1://left
		for (int c = 0; c < sizes; c++) {
			int next_y = (sizes-2);
			int y = (sizes-1);
			while (y > -1) {
				if (board[c][y] != 0) {
					if (y == 0) {
						scores.push(board[c][y]);
						break;
					}
					while (board[c][next_y] == 0) {
						next_y -= 1;
						if (next_y < 0) {
							scores.push(board[c][y]);
							y = -1;
							break;
						}
					}
					if (next_y >= 0) {
						if (board[c][y] == board[c][next_y]) {
							scores.push(2 * board[c][y]);
							y = next_y - 1;
							next_y = y - 1;
						}
						else {
							scores.push(board[c][y]);
							y = next_y;
							next_y = y - 1;
						}
					}
				}
				else {
					y -= 1;
					next_y -= 1;
				}
			}
			for (int z = (sizes-1); z >= 0; z--) {
				if (scores.empty()) {
					board[c][z] = 0;
				}
				else {
					board[c][z] = scores.front();
					scores.pop();
				}
			}
		}
		break;
	case 2://down
		for (int c = 0; c < sizes; c++) {
			int next_x = (sizes - 2);
			int x = (sizes - 1);
			while (x > -1) {
				if (board[x][c] != 0) {
					if (x == 0) {
						scores.push(board[x][c]);
						break;
					}
					while (board[next_x][c] == 0) {
						next_x -= 1;
						if (next_x < 0) {
							scores.push(board[x][c]);
							x = -1;
							break;
						}
					}
					if (next_x >= 0) {
						if (board[x][c] == board[next_x][c]) {
							scores.push(2 * board[x][c]);
							x = next_x - 1;
							next_x = x - 1;
						}
						else {
							scores.push(board[x][c]);
							x = next_x;
							next_x = x - 1;
						}
					}
				}
				else {
					x -= 1;
					next_x -= 1;
				}
			}
			for (int z = (sizes - 1); z >= 0; z--) {
				if (scores.empty()) {
					board[z][c] = 0;
				}
				else {
					board[z][c] = scores.front();
					scores.pop();
				}
			}
		}
		break;
	case 3://right
		for (int c = 0; c < sizes; c++) {
			int next_y = 1;
			int y = 0;
			while (y < sizes) {
				if (board[c][y] != 0) {
					if (y == (sizes - 1)) {
						scores.push(board[c][y]);
						break;
					}
					while (board[c][next_y] == 0) {
						next_y += 1;
						if (next_y >= sizes) {
							scores.push(board[c][y]);
							y = sizes;
							break;
						}
					}
					if (next_y < sizes) {
						if (board[c][y] == board[c][next_y]) {
							scores.push(2 * board[c][y]);
							y = next_y + 1;
							next_y = y + 1;
						}
						else {
							scores.push(board[c][y]);
							y = next_y;
							next_y = y + 1;
						}
					}
				}
				else {
					y += 1;
					next_y += 1;
				}
			}
			for (int z = 0; z <sizes; z++) {
				if (scores.empty()) {
					board[c][z] = 0;
				}
				else {
					board[c][z] = scores.front();
					scores.pop();
				}
			}
		}
		break;
	}
}
int cal_result(int sizes, int times) {
	if (times == 5) {
		for (int ab = 0; ab < sizes; ab++) {
			for (int cd = 0; cd < sizes; cd++) {
				if (board[ab][cd] > max_result) {
					max_result = board[ab][cd];
				}
			}
		}
		return max_result;
	}
	before.push(board);

	for (int k = 0; k < 4; k++) {
		cal_dir(sizes, k);
		cal_result(sizes, times + 1);
		board = before.top();
	}
	before.pop();

	return max_result;
}
int main() {
	int sizes,tempss;
	cin >> sizes;
	for (int i = 0; i < sizes; i++) {
		vector <int> elem(sizes);
		board.push_back(elem);
	}
	for (int j = 0; j < sizes; j++) {
		for (int i = 0; i < sizes; i++) {
			cin >> board[j][i];
			if (max_result < board[j][i]) {
				max_result = board[j][i];
			}
		}
	}
	cout << cal_result(sizes, 0)<<endl;
}
