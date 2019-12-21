// Baekjoon 2631
// Dynamic Programming

#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int N,answer, max_num;
array<int, 202>children;
array<int, 202>dp;

int main() {
	cin >> N;
	for (int i{ 1 }; i <= N; i++) {
		cin >> children[i];
	}
	answer = 1;
	for (int i{ 1 }; i <= N; i++) {
		if (dp[i] == 0)
			dp[i] = 1;
		for (int j{ 1 }; j < i; j++) {
			if (children[i] > children[j]) {
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;

				}
			}
		}
	}
	for (int i{ 1 }; i <= N; i++) {
		if (max_num < dp[i]) {
			max_num = dp[i];
		}
	}
	cout << N - max_num << endl;
}
