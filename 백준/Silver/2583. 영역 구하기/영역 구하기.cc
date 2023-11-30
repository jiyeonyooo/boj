#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int row, column;
int areas[100][100];
vector<int> result;
queue<pair<int, int>> q;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };

int bfs(int start_r , int start_c) {
	q.push(make_pair(start_r, start_c));
	areas[start_r][start_c] = -1;
	int area = 1;

	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dx[i];
			int nc = c + dy[i];

			if (nr < 0 || nr >= row || nc < 0 || nc >= column) continue;
			if (areas[nr][nc] != 0) continue;

			q.push(make_pair(nr, nc));
			areas[nr][nc] = -1; //visited
			area++;
		}
	}

	return area;

}

int main() {
	int rec, temp;
	int xl, yl, xr, yr;
	cin >> row >> column >> rec;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			areas[i][j] = 0;
		}
	}

	for (int i = 0; i < rec; i++) {
		cin >> xl >> yl >> xr >> yr;
		for (int p = row - yr; p < row - yl; p++) {
			for (int q = xl; q < xr; q++) {
				areas[p][q] = 1;
			}
		}
	}

	//areas[][] 배열 확인용
	/*for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << areas[i][j] << ' ';
		}
		cout << endl;
	}*/

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (areas[i][j] == 0) result.push_back(bfs(i, j));
		}
	}

	sort(result.begin(), result.end());
	cout << result.size() << '\n';
	for (auto i : result) cout << i << ' ';
	
	return 0;
}