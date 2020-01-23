// Baekjoon 1238
// Floyd-Warshall Algorithm

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

const int INF{ 100001 };
int N, M, X, s, e, t;
array<array<int, 1004>, 1004>dp;

void init() {
	for (int i{ 0 }; i <= N; i++) {
		for (int j{ 0 }; j <= N; j++) {
			dp[i][j] = INF;
		}
	}
}

void floyd() {
	for (int k{ 1 }; k <= N; k++) {
		for (int i{ 1 }; i <= N; i++) {
			for (int j{ 1 }; j <= N; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
}

int main() {
	cin >> N >> M >> X;
	init();
	for (int i{ 1 }; i <= M; i++) {
		cin >> s >> e >> t;
		dp[s][e] = t;
	}
	floyd();
	int max_t = 0;
	for (int i{ 1 }; i <= N; i++) {
		if (i == X) continue;
		if (max_t < dp[i][X] + dp[X][i])
			max_t = dp[i][X] + dp[X][i];
	}
	cout << max_t << endl;
}