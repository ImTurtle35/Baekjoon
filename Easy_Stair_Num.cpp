// Baekjoon 10844
// Dynamic Programming

#include <iostream>
#include <algorithm>

using namespace std;

int N;
long long int answer;
long long int dp[101][10];
int main() {
	cin >> N;
	for (int i{ 1 }; i <= 9; i++) {
		dp[1][i] = 1;
	}
	for (int i{ 2 }; i <= N; i++) {
		for (int j{ 0 }; j <= 9; j++) {
			if (j == 0)
				dp[i][j] = dp[i - 1][j + 1];
			else if (j == 9)
				dp[i][j] = dp[i - 1][j - 1];
			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1'000'000'000;
			}
		}
	}
	for (int i{ 0 }; i <= 9; i++) {
		answer += dp[N][i];
	}
	cout << answer % 1'000'000'000 << endl;
}