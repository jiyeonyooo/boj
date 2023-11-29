#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int painting[501][501];
int row, column;
queue<pair<int, int>>painting_stack;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

int check(int i, int j) {
	queue<pair<int, int>> painting_area;
	painting[i][j] = -1;
	painting_area.push(make_pair(i, j));
	int area = 1;
	while (!painting_area.empty()) {
		int p = painting_area.front().first;
		int q = painting_area.front().second;
		painting_area.pop();
		for (int i = 0; i < 4; i++) {
			int new_p = p + dx[i];
			int new_q = q + dy[i];
			if (new_p < 0 || new_p >= row || new_q < 0 || new_q >= column) continue;
			if (painting[new_p][new_q] != 1) continue;
			painting[new_p][new_q] = -1;
			painting_area.push(make_pair(new_p, new_q));
			area++;
		}
	}
	return area;
}

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int temp, area;
	int painting_num=0;
	int max_area = 0;

	cin >> row >> column;

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cin >> temp;
			painting[i][j] = temp;
		}
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			if (painting[i][j] == 1) {
				area = check(i, j);
				if (area != 0) painting_num++;
				if (area > max_area) max_area = area;
			}
		}
	}

	cout << painting_num << '\n' << max_area;
	return 0;
}