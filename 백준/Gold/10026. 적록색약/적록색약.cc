#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

char rgb[100][100];
int n;
int result = 0;
int cb_result = 0;
int cb_visited[100][100];
int visited[100][100];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void cb_bfs(int start_x, int start_y) {
	queue<pair<int, int>> q;
	q.push(make_pair(start_x, start_y));
	char color = rgb[start_x][start_y]; //구역의 color
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n) {
				if (color == 'B' && rgb[next_x][next_y] == color && cb_visited[next_x][next_y] == 0) {
					q.push(make_pair(next_x, next_y));
					cb_visited[next_x][next_y] = 1;
				}
				else if (color != 'B' && rgb[next_x][next_y] != 'B' && cb_visited[next_x][next_y] == 0) {
					q.push(make_pair(next_x, next_y));
					cb_visited[next_x][next_y] = 1;
				}
			}
		}
	}
}

void bfs(int start_x, int start_y) {
	queue<pair<int, int>> q;
	q.push(make_pair(start_x, start_y));
	char color = rgb[start_x][start_y]; //구역의 color

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n) {
				if (rgb[next_x][next_y] == color && visited[next_x][next_y] == 0) {
					q.push(make_pair(next_x, next_y));
					visited[next_x][next_y] = 1;
				}
			}
		}
	}
}

int main() {
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < n; j++) {
			rgb[i][j] = temp[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!cb_visited[i][j]) {
				cb_bfs(i, j);
				cb_result++;
			}
			if (!visited[i][j]) {
				bfs(i, j);
				result++;
			}
		}
	}

	cout << result << ' ' << cb_result;
	return 0;
}
