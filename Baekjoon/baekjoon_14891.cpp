#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <string>

using namespace std;

int wheel[33];
vector <pair<int,int>> rotates;

int reverse_dir(int direction) {
	if (direction > 0) {
		return -1;
	}
	else if (direction == 0) {
		return 0;
	}
	else {
		return 1;
	}
}
void howrotate(int wheel_num, int direction) {
	rotates.push_back(make_pair(wheel_num, direction));
	int wheels = wheel_num;
	int wheelss = wheel_num;
	int directs = direction;
	int directss = direction;
	int left = wheel_num-1;
	int right = wheel_num+1;

	while (left >= 0) {
		if (wheel[left*8 + 2] != wheel[wheels*8 + 6]) {
			directs = reverse_dir(directs);
			rotates.push_back(make_pair(left, directs));
		}
		else {
			rotates.push_back(make_pair(left, 0));
		}
		left -= 1;
		wheels -= 1;
		directs = rotates.back().second;
	}
	while (right <= 3) {
		if (wheel[right*8 + 6] != wheel[wheelss*8 + 2]) {
			directss = reverse_dir(directss);
			rotates.push_back(make_pair(right, directss));
		}
		else {
			rotates.push_back(make_pair(right, 0));
		}
		right += 1;
		wheelss += 1;
		directss = rotates.back().second;
	}
}
void rotate() {
	while (!rotates.empty()) {
		int each_direc = rotates.back().second;
		int each_wheel = rotates.back().first;
		int temp,wherestart;
		if (each_direc == 1) {
			wherestart = each_wheel * 8 + 7;
			temp = wheel[wherestart];
			for (int s = wherestart; s > (wherestart-7); s--) {
				wheel[s] = wheel[s - 1];
			}
			wheel[wherestart-7] = temp;
		}
		else if(each_direc==-1) {
			wherestart = each_wheel * 8;
			temp = wheel[wherestart];
			for (int t = wherestart; t < (wherestart+7); t++) {
				wheel[t] = wheel[t + 1];
			}
			wheel[wherestart+7] = temp;
		}
		rotates.pop_back();
	}
}
int cal_score(int wheel_nums) {
	switch (wheel_nums) {
	case 0:
		return 1;
	case 1:
		return 2;
	case 2:
		return 4;
	case 3: 
		return 8;
	}
}
int main() {
	int scores = 0;
	int rot_num, wheel_num, direction;
	string wheel_temp, all_wheel;
	char wheeltemp[34];
	for (int k = 0; k < 4; k++) {
		cin >> wheel_temp;
		all_wheel += wheel_temp;
	}
	strcpy_s(wheeltemp, all_wheel.c_str());
	for (int p = 0; p < 32; p++) {
		wheel[p] = wheeltemp[p]-'0';
	}

	cin >> rot_num;
	for (int j = 0; j < rot_num; j++) {
		cin >> wheel_num >> direction;
		howrotate(wheel_num - 1, direction);
		rotate();
	}
	for (int d = 0; d < 4; d++) {
		if (wheel[d * 8] == 1) {
			scores += cal_score(d);
		}
	}
	cout << scores << endl;
}