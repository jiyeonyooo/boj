#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>

using namespace std;

int maze[100][100];
int dis[100][100];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };

int mazing(int n, int m) {
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	dis[0][0] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		maze[x][y] = -1;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (maze[nx][ny] != 1) continue;
	
			q.push(make_pair(nx, ny));
			maze[nx][ny] = -1;
			dis[nx][ny] = dis[x][y] + 1;

		}
	}

	return dis[n - 1][m - 1];
}

int main() {
	int n, m; //nxm 배열 2-100
	cin >> n >> m;
	int move = 1;
	string rows;
	for (int i = 0; i < n; i++) {
		cin >> rows;
		for (int j = 0; j < m; j++) {
			if (rows[j] == '1') maze[i][j] = 1;
			else maze[i][j] = 0;
		}
	}

	cout << mazing(n, m);

	return 0;

}