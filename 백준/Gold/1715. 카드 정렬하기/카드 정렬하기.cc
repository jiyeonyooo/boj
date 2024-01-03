#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
	int num, temp;
	long long result = 0;
	priority_queue<int, vector<int>, greater<int>> sorting;
	cin >> num;

	if (num == 1) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < num; i++) {
		cin >> temp;
		sorting.push(temp);
	}
	
	while (sorting.size() > 2) {
		int first = sorting.top();
		sorting.pop();
		int second = sorting.top();
		sorting.pop();
		result += (first + second);
		sorting.push(first + second);
	}

	while (!sorting.empty()) {
		int a = sorting.top();
		result += a;
		sorting.pop();
	}

	cout << result;
	return 0;
}