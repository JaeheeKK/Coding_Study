#include<iostream>
#include<queue>
#include<cstring>

using namespace std;
bool edges[1001][1001]; //간선
bool check[1001] = { 0, }; // 방문했다면 check
queue <int> result; // 결과 값 출력

void DFS(int start, int dot) { //DFS는 재귀로
	for (int a = 1; a <= dot; a++) {
		if (!check[a] && edges[start][a]) {
			result.push(a);
			check[a] = 1;
			DFS(a, dot);
		}
	}
	while(!result.empty()){
		cout << result.front() << " ";
		result.pop();
	}
}
void BFS(int start, int dot) {
	queue <int> result2;
	bool check2[1001] = { 0, };
	result2.push(start);
	check2[start] = 1;
	while(!result2.empty()) {
		for (int c = 1; c <= dot; c++) {
			if (edges[result2.front()][c] && !check2[c]) {
				result2.push(c);
				check2[c] = 1;
			}
		}
		cout << result2.front() << " ";
		result2.pop();
	}
}
int main() {
	int dot, edge, start;
	cin >> dot >> edge >> start;
	for (int k = 0; k <= dot; k++) {
		memset(edges[k], 0, sizeof(bool) * (dot+1));
	}
	check[start] = 1;
	result.push(start);

	for (int i = 0; i < edge; i++) {
		int first, second;
		cin >> first >> second;
		edges[first][second] = 1;
		edges[second][first] = 1;
	}
	DFS(start, dot);
	cout << endl;
	BFS(start, dot);
	cout << endl;
}