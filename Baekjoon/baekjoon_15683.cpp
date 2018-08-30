#include <iostream>
#include <vector>
#include<stack>
#include <utility>

using namespace std;

vector<pair<int, int>> camera;
vector <int> cams;
vector <int> nows;
vector<vector<int>> check;
stack<vector<vector<int>>> before;
int office[9][9];
int now, maxs = 0;
int results = 0;

int check_cam(int camera_num) {
	switch (camera_num) {
	case 1: 
	case 3:
	case 4:
		return 4;
	case 2:
		return 2;
	case 5:
		return 1;

	}
}
int check_cctv(int x, int y, int height, int width, int cases) {
	int room = 0;

	if (cases == 0) {//right
		while (y <= width) {
			if (office[x][y] == 6) {
				return room;
			}
			if (check[x][y]==0) {
				check[x][y] = 1;
				y += 1;
				room += 1;
			}
			else {
				y += 1;
			}
		}
	}
	else if (cases == 1) {//left
		while (y >=1 ) {
			if (office[x][y] == 6) {
				return room;
			}
			if (check[x][y]==0) {
				check[x][y] = 1;
				y -= 1;
				room += 1;
			}
			else {
				y -= 1;
			}
		}
	}
	else if (cases == 2) {//down
		while (x <= height) {
			if (office[x][y] == 6) {
				return room;
			}
			if (check[x][y]==0) {
				check[x][y] = 1;
				x += 1;
				room += 1;
			}
			else {
				x += 1;
			}
		}
	}
	else if (cases == 3) {//up
		while (x >= 1) {
			if (office[x][y] == 6) {
				return room;
			}
			if (check[x][y]==0) {
				check[x][y] = 1;
				x -= 1;
				room += 1;
			}
			else {
				x -= 1;
			}
		}
	}
	return room;
}
int cal_max(int height, int width, int cameras, int camera_size) {
	if (cameras>camera_size) {
		return results;
	}
	before.push(check);

	int camera_num = cams[cameras-1];
	int x = camera[cameras - 1].first;
	int y = camera[cameras - 1].second;
	int cam_rotate = check_cam(camera_num);

	for (int h = 0; h < cam_rotate; h++) {//각 카메라마다 방향
		if (camera_num == 1) {
			now =  check_cctv(x, y, height, width, h);
			nows.push_back(now);
			maxs += now;
		}
		else if (camera_num == 2) {
			now = check_cctv(x, y, height, width, 2 * h);
			now += check_cctv(x, y, height, width, 2 * h + 1);
			nows.push_back(now);
			maxs += now;
		}
		else if (camera_num == 3) {
			if (h <= 1) {
				now = check_cctv(x, y, height, width, h);
				now += check_cctv(x, y, height, width, 2);
				nows.push_back(now);
				maxs += now;
			}
			else {
				now = check_cctv(x, y, height, width, h-2);
				now += check_cctv(x, y, height, width, 3);
				nows.push_back(now);
				maxs += now;
			}
		}
		else if (camera_num == 4) {
			if (h <= 1) {
				now = check_cctv(x, y, height, width, h);
				now += check_cctv(x, y, height, width, 2);
				now += check_cctv(x, y, height, width, 3);
				nows.push_back(now);
				maxs += now;
			}
			else {
				now = check_cctv(x, y, height, width, 0);
				now += check_cctv(x, y, height, width, 1);
				now += check_cctv(x, y, height, width, h);
				nows.push_back(now);
				maxs += now;
			}
		}
		else if (camera_num == 5) {
			now = check_cctv(x, y, height, width, 0);
			now += check_cctv(x, y, height, width, 1);
			now += check_cctv(x, y, height, width, 2);
			now += check_cctv(x, y, height, width, 3);
			nows.push_back(now);
			maxs += now;
		}
		cal_max(height, width,cameras+1, camera_size);
		if (results < maxs) {
			results = maxs;
		}
		check = before.top();
		maxs -= nows.back();
		nows.pop_back();
	}
	before.pop();
	return results;
}
int main() {
	int height, width, wall = 0;
	cin >> height >> width;

	for (int i = 0; i <= height; i++) {
		vector <int> elem(width+1);
		check.push_back(elem);
	}
	for(int j=1; j<=height; j++){
		for (int k = 1; k <= width; k++) {
			cin >> office[j][k];
			check[j][k] = office[j][k];
			if (office[j][k] != 0) {
				wall += 1;
			}
			if (office[j][k] > 0 && office[j][k] < 6) {
				camera.push_back(make_pair(j, k));
				cams.push_back(office[j][k]);
			}
		}
	}
	int camera_size = cams.size();
	int maxs = 0;
	cout << height*width-(cal_max(height, width,1,camera_size))-wall << endl;
}