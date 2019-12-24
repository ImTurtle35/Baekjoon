// baekjoon 10160
// Dynamic programming
#include <iostream>
#include <cmath>

using namespace std;

int N, K;
long long int dp[1000002];

int main() {
	cin >> N >> K;
	dp[0] = 1;
	for (int i{ 1 }; i < 5; i++) {
		dp[i] = dp[i - 1] * K;
	}
	for (int i{ 5 }; i <= 6; i++) {
		dp[i] = ((dp[i - 1] * K) - (dp[i - 5] * 2)) % 1000000009;
	}
	for (int i{ 7 }; i <= N; i++) {
		dp[i] = ((dp[i - 1] * K) - (dp[i - 5] * 2) + dp[i-7]) % 1000000009;
		if (dp[i] < 0) {
			dp[i] += 1000000009;
		}
	}
	cout << dp[N] << endl;
}