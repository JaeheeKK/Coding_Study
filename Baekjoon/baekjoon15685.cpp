#include<iostream>
#include <vector>

using namespace std;

int check[101][101];
int max_x = -1, max_y = -1;//정사각형 찾을 때 map크기 조정
int min_x = 101, min_y = 101;//정사각형 찾을 때 map크기 조정

struct pos {
	int x;
	int y;
	int direct;
	int gener;
};

vector <pos> dragons;
//vector <pos> checks;

void cal_dragon_curve(int xx, int yy, int geners) {
	if (geners == 0) {
		return;
	}
	int last_x=xx;
	int last_y = yy;
	int stack_size = dragons.size();
	for (int k = (stack_size-1); k >= 0; k--) {
		switch (dragons[k].direct) {
		case 0:
			last_x += 1;
			check[last_x][last_y] = 1;
			dragons.push_back({ last_x,last_y,1,geners - 1 });
			break;
		case 1:
			last_y -= 1;
			check[last_x][last_y] = 1;
			dragons.push_back({ last_x,last_y,2,geners - 1 });
			break;
		case 2:
			last_x -= 1;
			check[last_x][last_y] = 1;
			dragons.push_back({ last_x,last_y,3,geners - 1 });
			break;
		case 3:
			last_y += 1;
			check[last_x][last_y] = 1;
			dragons.push_back({ last_x,last_y,0,geners - 1 });
			break;
		}
	}
	cal_dragon_curve(last_x, last_y, geners - 1);
}

int cal_rect() {
	int result = 0;
	for (int a = 0; a < 100; a++) {
		for (int b = 0; b < 100; b++) {
			if ((check[a][b] == 1 && check[a + 1][b]==1) && (check[a][b + 1]==1 && check[a + 1][b + 1]==1)) {
				result += 1;
			}
		}
	}
	return result;
}

int main() {
	int curves,xx,yy,directs,geners;
	cin >> curves;

	for (int i = 0; i < curves; i++) {
		cin >> xx >> yy >> directs >> geners;

		check[xx][yy] = 1;
		switch (directs) {
		case 0:
			xx += 1;
			directs = 1;
			break;
		case 1:
			yy -= 1;
			directs = 2;
			break;
		case 2:
			xx -= 1;
			directs = 3;
			break;
		case 3:
			yy += 1;
			directs = 0;
			break;
		}
		check[xx][yy] = 1;
		dragons.push_back({ xx,yy,directs,geners });
		cal_dragon_curve(xx, yy, geners);
		dragons.clear();
	}
	cout << cal_rect() << endl;
}