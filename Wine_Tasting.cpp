// Baekjoon 2156
// Dynamic Programming

#include <iostream>
#include <algorithm>

using namespace std;

int N;
int wine[10001];
int dp[10001][4];

int main() {
	cin >> N;
	for (int i{ 1 }; i <= N; i++) {
		cin >> wine[i];
	}
	dp[1][2] = wine[1]; dp[1][3] = wine[1];
	for (int i{ 2 }; i <= N; i++) {
		dp[i][0] = dp[i - 1][1];
		dp[i][1] = max(dp[i - 1][2], dp[i - 1][3]);
		dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + wine[i];
		dp[i][3] = dp[i - 1][2] + wine[i];
	}
	cout << max(max(dp[N][0],dp[N][3]), max(dp[N][1], dp[N][2]));
}