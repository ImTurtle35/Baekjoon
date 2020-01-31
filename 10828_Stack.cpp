// Baekjoon 10828

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
string input;
vector<int>vec;

void push(int n) {
	vec.push_back(n);
}

void pop() {
	if (vec.size() == 0) cout << "-1\n";
	else {
		cout << vec[vec.size() - 1] << "\n";
		vec.pop_back();
	}
}

void size() {
	cout << vec.size() << endl;
}

void empty() {
	if (vec.size() == 0) cout << "1\n";
	else cout << "0\n";
}

void top() {
	if (vec.size() == 0) cout << "-1\n";
	else cout << vec[vec.size() - 1] << "\n";
}

int main() {
	cin.tie();
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i{ 0 }; i < N; i++) {
		cin >> input;
		if (input == "push") {
			int num;
			cin >> num;
			push(num);
		}
		else if (input == "pop") pop();
		else if (input == "size") size();
		else if (input == "empty") empty();
		else if (input == "top") top();
	}
}