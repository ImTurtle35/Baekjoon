// Baekjoon 10845
// Queue
#include <iostream>
#include <queue>
#include <string>

using namespace std;

string input;
int N, num;
queue<int> que;

int main() {
	cin >> N;
	for (int i{ 0 }; i < N; i++) {
		cin >> input;
		if (input == "push") {
			cin >> num;
			que.push(num);
		}
		else if (input == "front") {
			if (que.empty() == 1) {
				cout << -1 << endl;
			}
			else
			cout << que.front() << endl;
		}
		else if (input == "back") {
			if (que.empty() == 1) {
				cout << -1 << endl;
			}
			else
			cout << que.back() << endl;
		}
		else if (input == "size") {
			cout << que.size() << endl;
		}
		else if (input == "empty") {
			cout << que.empty() << endl;
		}
		else if (input == "pop") {
			if (que.empty() == 1)
				cout << -1 << endl;
			else {
				cout << que.front() << endl;
				que.pop();
			}
		}
	}
}