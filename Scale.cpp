// Baekjoon(10159)
// Floyd-Warshall Algorithm

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

const int INF = 2010;
int N, M, a, b;
array<array<int, 101>, 101> dp;

void Init() {
	for (int i{ 0 }; i <= N; i++) {
		for (int j{ 0 }; j <= N; j++) {
			dp[i][j] = INF;
		}
	}
}

void Fwa() {
	for (int k{ 1 }; k <= N; k++) {
		for (int i{ 1 }; i <= N; i++) {
			for (int j{ 1 }; j <= N; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	for (int i{ 1 }; i <= N; i++) {
		for (int j{ 1 }; j <= N; j++) {
			if (dp[i][j] < INF) {
				dp[j][i] = dp[i][j];
			}
		}
	}
}

void count(int n) {
	int answer = 0;
	for (int i{ 1 }; i <= N; i++) {
		if (i == n || dp[n][i] < INF)
			continue;
		answer++;
	}
	cout << answer << endl;
}

int main() {
	cin >> N;
	cin >> M;
	Init();
	for (int i{ 0 }; i < M; i++) {
		cin >> a >> b;
		dp[a][b] = 1;
	}
	Fwa();
	for (int i{ 1 }; i <= N; i++) {
		count(i);
	}
}