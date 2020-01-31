// Baekjoon 1978
#include <iostream>

using namespace std;

int N, input, answer;

int main() {
	cin.tie();
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i{ 0 }; i < N; i++) {
		cin >> input;
		if (input == 1) continue;
		answer++;
		for (int j{ 2 }; j < input; j++) {
			if (input % j == 0) {
				answer--;
				break;
			}
		}
	}
	cout << answer << "\n";
}