#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	 
	string input;
	int result[2] = { 0, };

	cin >> input;
	int temp = input[0];
	result[int(temp) - '0']++;

	for (int i = 0; i < input.length(); i++) {
		if (input[i] != temp) {
			result[int(input[i]) - '0']++;
			temp = input[i];
		}
	}

	//cout << result[0] << ' ' << result[1] << '\n';

	if (result[0] < result[1]) cout << result[0];
	else cout << result[1];

	return 0;
}