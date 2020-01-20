// Baekjoon(16358)
// Floyd-Warshall Algorithm

#include <iostream>
#include <array>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 1000001;
int m, n, save;
array<array<int, 501>, 501> dp;
array<array<int, 501>, 501> rate;
array<array<int, 501>, 501> answer;
queue<int>que;

void Fwa() {
	for (int k{ 1 }; k <= m; k++) {
		for (int i{ 1 }; i <= m; i++) {
			for (int j{ 1 }; j <= m; j++) {
				answer[i][j] = max(answer[i][j], min(answer[i][k] , answer[k][j]));
			}
		}
	}
}

void rating(int n) {
	for (int i{ 1 }; i <= m; i++) {
		for (int j{ 1 }; j <= m; j++) {
			if (i == j)
				continue;
			else {
				if (dp[n][i] < dp[n][j])
					rate[i][j] += 1;
			}
		}
	}
}

void compare() {
	for (int i{ 1 }; i <= m; i++) {
		for (int j{ i }; j <= m; j++) {
			if (i == j || rate[i][j] == rate[j][i]) {
				answer[j][i] = 0;
			}
			else {
				if (rate[i][j] > rate[j][i]) {
					answer[j][i] = rate[i][j];
					answer[i][j] = 0;
				}
				else {
					answer[i][j] = rate[j][i];
					answer[j][i] = 0;
				}
			}
		}
	}
}

int main() {
	cin >> m >> n;
	for (int i{ 1 }; i <= n; i++) {
		for (int j{ 1 }; j <= m; j++) {
			cin >> save;
			if (save == 0)
				dp[i][j] = INF;
			else
				dp[i][j] = save;
		}
		rating(i);
	}
	compare();
	Fwa();
	int min_num = INF;
	for (int i{ 1 }; i <= m; i++) {
		int jw = 0;
		for (int j{ 1 }; j <= m; j++) {
			jw += answer[i][j];
		}
		if (jw <= min_num) {
			if (jw < min_num) {
				while (!que.empty()) {
					que.pop();
				}
			}
			min_num = jw;
			que.push(i);
		}
	}
	while (!que.empty()) {
		cout << que.front() << " ";
		que.pop();
	}
}