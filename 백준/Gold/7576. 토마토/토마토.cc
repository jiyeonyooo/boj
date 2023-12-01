#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

//모두 익어있는 상태 return 0
//모든 토마토가 익을 수 없는 상태 return -1

int tomato[1000][1000];
int ripe_days[1000][1000];
queue<pair<int, int>> ripe_tomato;
int row, column;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

int ripe() {
	int days = 0;

	while (!ripe_tomato.empty()) {
		int x = ripe_tomato.front().first;
		int y = ripe_tomato.front().second;
		//cout << x << ' ' << y << endl;
		ripe_tomato.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= row || ny < 0 || ny >= column) continue;
			if (tomato[nx][ny] != 0) continue;
			tomato[nx][ny] = 1;
			ripe_tomato.push(make_pair(nx, ny));
			ripe_days[nx][ny] = ripe_days[x][y] + 1;
			if (ripe_days[nx][ny] > days) days = ripe_days[nx][ny];
		}
	}

	return days;
}

bool check() {
	for (int i = 0; i < row; i++){
		for (int j = 0; j < column; j++) {
			if (tomato[i][j] == 0) return false;
		}
	}
	return true;
}

int main() {
	int temp, result;
	cin >> column >> row;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cin >> temp;
			if (temp == 1) {
				ripe_tomato.push(make_pair(i, j));
				ripe_days[i][j] = 0;
			}
			else if (temp == -1) ripe_days[i][j] = -1; //익을 수 없음
			else ripe_days[i][j] = 0;
			tomato[i][j] = temp;
		}

	}

	result = ripe();

	if (check()) cout << result;
	else cout << -1;

	return 0;

}