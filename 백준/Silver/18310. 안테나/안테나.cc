#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int distance(vector<int> v, int index) {
	int result = 0;
	for (int i = 0; i < v.size(); i++) {
		if (i <= index) result += (v[index] - v[i]);
		else result -= (v[index] - v[i]);
	}
	return result;
}

int main() {
	int num, location;
	cin >> num;
	vector<int> houses;
	for (int i = 0; i < num; i++) {
		cin >> location;
		houses.push_back(location);
	}
	sort(houses.begin(), houses.end());
	
	if (num % 2 != 0) cout << houses[num / 2];
	else {
		if (distance(houses, num / 2 - 1) <= distance(houses, num / 2)) cout << houses[num / 2 - 1];
		else cout << houses[num / 2];
	}
}
