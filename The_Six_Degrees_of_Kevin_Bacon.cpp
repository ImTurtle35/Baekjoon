// Baekjoon 1389
// Floyd-Warshall Algorithm
#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

const int INF = 5001;
int N, M, a, b, min_num, answer;
array<array<int, 101>, 101>dp;

int main() {
	min_num = INF;
	cin >> N >> M;
	for (int i{ 1 }; i <= N; i++) {
		for (int j{ 1 }; j <= N; j++) {
			dp[i][j] = INF;
		}
	}
	for (int i{ 0 }; i < M; i++) {
		cin >> a >> b;
		dp[a][b] = 1;
		dp[b][a] = 1;
	}
	for (int k{ 1 }; k <= N; k++) {
		for (int i{ 1 }; i <= N; i++) {
			for (int j{ 1 }; j <= N; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	for (int i{ 1 }; i <= N; i++) {
		int save = 0;
		for (int j{ 1 }; j <= N; j++) {
			if (i == j)
				continue;
			else
				save += dp[i][j];
		}
		if (min_num > save) {
			min_num = save;
			answer = i;
		}
	}
	cout << answer << endl;
}