#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int road[1000][1000];
int visited[1000][1000][2]; //[0] -> 벽을 부수지 않음, [1] -> 벽을 부숨
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int bfs(int row, int column) {
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(0, 0),0));
	visited[0][0][0] = 1; //방문

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int wall = q.front().second;
		q.pop();

		if (x == row - 1 && y == column - 1) return visited[x][y][wall]; //도착지 도착
		
		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];

			if (next_x >= 0 && next_x < row && next_y >= 0 && next_y < column) {
				if (road[next_x][next_y] == 1 && wall == 0) { //벽을 처음 만난 경우
					q.push(make_pair(make_pair(next_x, next_y), 1));
					visited[next_x][next_y][1] = visited[x][y][wall] + 1;
				}
				else if (road[next_x][next_y] == 0 && visited[next_x][next_y][wall] == 0) {
					q.push(make_pair(make_pair(next_x, next_y), wall));
					visited[next_x][next_y][wall] = visited[x][y][wall] + 1;
				}
			}	
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m; //row, column
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < m; j++) {
			road[i][j] = temp[j] - '0'; //int형으로 변환하여 road 배열에 저장
		}
	}

	cout << bfs(n, m);

	return 0;
}