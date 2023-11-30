#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int chess[300][300];
int dis[300][300];
int moving_x[8] = { 2,2,-2,-2,1,1,-1,-1 };
int moving_y[8] = { 1,-1,1,-1,2,-2,2,-2 };
queue<pair<int, int>> q;
int x, y, dest_x, dest_y; //체스판의 한 변의 길이, (x,y)시작점, (dest_x, dest_y) 도착점

int bfs(int x, int y, int size) {
	q.push(make_pair(x, y));
	chess[x][y] = -1; //visited
	dis[x][y] = 0;

	while (!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int new_x = nx + moving_x[i];
			int new_y = ny + moving_y[i];
			if (new_x < 0 || new_x >= size || new_y < 0 || new_y >= size) continue;
			if (chess[new_x][new_y] != 0) continue;

			q.push(make_pair(new_x, new_y));
			chess[new_x][new_y] = -1;
			dis[new_x][new_y] = dis[nx][ny] + 1;
		}
	}

	return dis[dest_x][dest_y];
}

int main() {
	int tc, size; //test case 개수
	cin >> tc;
	
	for (int i = 0; i < tc; i++) {
		cin >> size >> x >> y >> dest_x >> dest_y;
		for (int p = 0; p < size; p++) {
			for (int q = 0; q < size; q++) {
				chess[p][q] = 0;
			}
		}

		if (x == dest_x && y == dest_y) cout << 0 << '\n';
		else cout << bfs(x, y, size) << '\n';
	}

	return 0;
}