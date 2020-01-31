// Bakejoon 2164

#include <iostream>
#include <queue>

using namespace std;

int N;
queue<int>que;

int main() {
	cin.tie();
	ios::sync_with_stdio(false);
	cin >> N;
	if (N == 1) cout << 1 << "\n";
	else {
		for (int i{ 2 }; i <= N; i++) {
			que.push(i);
		}
		for (int i{ 2 }; i < N; i++) {
			que.push(que.front());
			que.pop();
			que.pop();
		}
		cout << que.front() << "\n";
	}
}