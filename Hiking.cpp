#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int N, M, T, D, answer;
string line;
typedef pair<int, int>P;
array<array<int, 26>, 26>map;
array<array<int, 626>, 626>dp;
int i_cal[4] = { -1, +1, 0, 0 };
int j_cal[4] = { 0, 0, -1, +1 };

void cal(int i, int j, int n) {
	int ic = i + i_cal[n];
	int jc = j + j_cal[n];
	int h = map[i][j];
	int c = map[ic][jc];
	if (c == -1)
		return;
	int h_pos = i * M + j;
	int c_pos = ic * M + jc;
	if (h == c) { dp[h_pos][c_pos] = 1; dp[c_pos][h_pos] = 1; }
	else if (h > c) {
		if (h - c <= T) { 
			dp[c_pos][h_pos] = (h - c) * (h - c);
			dp[h_pos][c_pos] = 1;
		}
	}
	else {
		if (c - h <= T) { 
			dp[h_pos][c_pos] = (c - h) * (c - h);
			dp[c_pos][h_pos] = 1;
		}
	}
}

void store(int i, int j) {
	if (i > 0) cal(i,j,0);
	// if (i < N-1) cal(i,j,1);
	if (j > 0) cal(i,j,2);
	// if (j < M-1) cal(i,j,3);
}

void floyd() {
	for (int k{ 0 }; k < N * M; k++) {
		for (int i{ 0 }; i < N * M; i++) {
			for (int j{ 0 }; j < N * M; j++) {
				int save = dp[i][k] + dp[k][j];
				dp[i][j] = min(dp[i][j], save);
			}
		}
	}
}

int main() {
	cin >> N >> M >> T >> D;
	for (int i{ 0 }; i < N; i++) {
		for (int j{ 0 }; j < M; j++) {
			map[i][j] = -1;
		}
	}
	for (int i{ 0 }; i < N * M; i++) {
		for (int j{ 0 }; j < N * M; j++) {
			dp[i][j] = INF;
		}
	}
	for (int i{ 0 }; i < N; i++) {
		cin >> line;
		for (int j{ 0 }; j < M; j++) {
			int H;
			if (line[j] >= 'A' && line[j] <= 'Z') H = line[j] - 'A';
			else if (line[j] >= 'a' && line[j] <= 'z') H = line[j] - 'a' + 26;
			map[i][j] = H;
			store(i, j);
	    }
	}
	if (N * M == 1) {
		cout << map[0][0] << endl;
		return 0;
	}
	floyd();
	for (int i{ 1 }; i < N * M; i++) {
		if (dp[0][i] + dp[i][0] <= D && answer < map[i / M][i % M])
			answer = map[i / M][i % M];
	}
	if (answer == 0) answer = map[0][0];
	else if (map[0][0] > answer) answer = map[0][0];
	cout << answer << endl;
}