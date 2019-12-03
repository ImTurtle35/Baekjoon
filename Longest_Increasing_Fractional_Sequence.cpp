// Baekjoon 11053
// Dynamic Programming
#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int N, input, answer, max_count;
array<int, 1002>A;
array<int, 1002>dp;

int main() {
	cin >> N;
	answer = 1;
	for (int i{ 0 }; i < N; i++) {
		cin >> input;
		A[i] = input;
	}
	for (int i{ 0 }; i < N; i++) {
		dp[i] = 1;
	}
	for (int i{ 1 }; i < N; i++) {
		int count = 1;
		int save = 1001;
		for (int j{ 0 }; j < i; j++) {
			if (A[j] < A[i]) {
				if (dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
				}
			}
		}
		if (dp[i] > answer)
			answer = dp[i];
	}
	
	cout << answer << endl;
}