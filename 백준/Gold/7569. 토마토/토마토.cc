#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

//모두 익어있는 상태 return 0
//모든 토마토가 익을 수 없는 상태 return -1

int tomato[100][100][100];
int ripe_days[100][100][100]; //[z][x][y]
queue<pair<int, pair<int,int>>> ripe_tomato;
int row, column, height;
int dx[6] = { 0,0,1,-1,0,0 };
int dy[6] = { 1,-1,0,0,0,0 };
int dz[6] = { 0,0,0,0,1,-1 }; //height 이동 

int ripe() {
	int days = 0;

	while (!ripe_tomato.empty()) {
		int z = ripe_tomato.front().first;
		int x = ripe_tomato.front().second.first;
		int y = ripe_tomato.front().second.second;
		//cout << x << ' ' << y << endl;
		ripe_tomato.pop();
		for (int i = 0; i < 6; i++) {
			int nz = z + dz[i];
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= row || ny < 0 || ny >= column || nz < 0 || nz >= height) continue;
			if (tomato[nz][nx][ny] != 0) continue;
			tomato[nz][nx][ny] = 1;
			ripe_tomato.push(make_pair(nz, make_pair(nx,ny)));
			ripe_days[nz][nx][ny] = ripe_days[z][x][y] + 1;
			if (ripe_days[nz][nx][ny] > days) days = ripe_days[nz][nx][ny];
		}
	}

	return days;
}

bool check() {
	for (int k = 0; k < height; k++) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				if (tomato[k][i][j] == 0) return false;
			}
		}
	}
	return true;
}

int main() {
	int temp, result;
	cin >> column >> row >> height;
	for (int k = 0; k < height; k++) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				cin >> temp;
				if (temp == 1) {
					ripe_tomato.push(make_pair(k, make_pair(i, j)));
					ripe_days[k][i][j] = 0;
				}
				else if (temp == -1) ripe_days[k][i][j] = -1; //익을 수 없음
				else ripe_days[k][i][j] = 0;
				tomato[k][i][j] = temp;
			}
		}
	}

	result = ripe();

	if (check()) cout << result;
	else cout << -1;

	return 0;

}