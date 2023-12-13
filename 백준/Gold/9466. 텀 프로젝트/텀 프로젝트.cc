#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h> //memset함수
#define MAX 100001

using namespace std;

int want[MAX] = { 0, };
bool visited[MAX] = { 0, };
bool done[MAX] = { 0, };

int members_num = 0;

void dfs(int current_student) {
	int next_student = want[current_student];
	visited[current_student] = 1;
	if (!visited[next_student]) dfs(next_student);
	else {
		if (!done[next_student]) { //방문은 되었으나, 팀 결정이 안된 경우 -> 사이클이 만들어짐
			for (int i = next_student; i != current_student; i = want[i]) members_num++;
			members_num++;
		}
	}
	done[current_student] = 1;
}

int main() {
	int tc, students_num;
	cin >> tc; //test case 개수

	for (int i = 0; i < tc; i++) {

		memset(want, 0, sizeof(want));
		memset(visited, 0, sizeof(visited));
		memset(done, 0, sizeof(done));

		cin >> students_num; //학생수

		for (int j = 1; j <= students_num; j++) { //학생의 number는 1부터 시작이므로 j값을 1부터로 설정
			cin >> want[j];
		}
		members_num = 0;
		for (int j = 1; j <= students_num; j++) {
			if (!visited[j]) dfs(j);
		}
		cout << students_num - members_num << '\n';
		
	}

	return 0;
}