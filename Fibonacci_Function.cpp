// Baekjoon 1003
// Dynamic Programming

#include <iostream>

using namespace std;

int T, N;
int dp[41];

int fibonacci(int n) {
	if (n <= 1) {
		return dp[n] = n;
	}
	else if (dp[n] != 0) {
		return dp[n];
	}
	else {
		return dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int main() {
	cin >> T;
	for (int i{ 0 }; i < T; i++) {
		cin >> N;
		fibonacci(N);
		if (N == 0) {
			cout << "1 0\n";
		}
		else if (N == 1) {
			cout << "0 1\n";
		}
		else
			cout << dp[N - 1] << " " << dp[N] << endl;
	}
}
