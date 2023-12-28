#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Student {

public:
	string name;
	int korean;
	int english;
	int math;

	Student(string name, int korean, int english, int math) { //생성자
		this->name = name;
		this->korean = korean;
		this->english = english;
		this->math = math;
	}
	void print_name() {
		cout << name << '\n';
	}

};

bool cmp(Student s1, Student s2) {
	if (s1.korean != s2.korean) return s1.korean > s2.korean;
	else if (s1.english != s2.english) return s1.english < s2.english;
	else if (s1.math != s2.math) return s1.math > s2.math;
	else return s1.name < s2.name;
}

int main() {
    std::cin.tie(0); std::cout.tie(0);
    std::ios_base::sync_with_stdio(false);
	int num, ko, en, math;
	string name;
	cin >> num;
	vector<Student> info;

	for (int i = 0; i < num; i++) {
		cin >> name >> ko >> en >> math;
		info.push_back(Student(name, ko, en, math));
	}

	sort(info.begin(), info.end(), cmp);

	for (int i = 0; i < num; i++) {
		info[i].print_name();
	}

	return 0;
}
