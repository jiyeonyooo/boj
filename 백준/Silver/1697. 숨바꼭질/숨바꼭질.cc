#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

queue<int> q;
int result = 0;
int x[100001] = {0, };

int bfs(int os, int ys) {
    
    if (os == ys ) return 0;
    
	q.push(os);
	x[os] = 0;
    
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		if (now - 1 == ys || now + 1 == ys || 2 * now == ys) {
			x[ys] = x[now] + 1;
			break;
		}
		if (now - 1 >= 0 && x[now - 1] == 0) {
			q.push(now - 1);
			x[now - 1] = x[now] + 1;
		}
		if (now + 1 <= 100000 && x[now + 1] == 0) {
			q.push(now + 1);
			x[now + 1] = x[now] + 1;
		}
		if (2*now <= 100000 && x[2*now] == 0) {
			q.push(2*now);
			x[2*now] = x[now] + 1;
		}
	}

	return x[ys];
}

int main() {
	int os, ys; //older sister 언니 위치, younger sister 동생 위치
	cin >> os >> ys;
 
	cout << bfs(os, ys);

}