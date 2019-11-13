// Baekjoon 1012
// Stack, DFS

#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int T, M, N, K, point_x, point_y, answer;
int cabbage[51][51];
int check[51][51];

void dfs(int px, int py, int x_max, int y_max) {
	if (px < x_max && check[px + 1][py] == 0 && cabbage[px + 1][py] == 1) {
		check[px + 1][py] = 1;
		dfs(px + 1, py, x_max, y_max);
	}
	if (py < y_max && check[px][py + 1] == 0 && cabbage[px][py + 1] == 1) {
		check[px][py + 1] = 1;
		dfs(px, py + 1, x_max, y_max);
	}
	if (px > 0 && check[px - 1][py] == 0 && cabbage[px - 1][py] == 1) {
		check[px - 1][py] = 1;
		dfs(px - 1, py, x_max, y_max);
	}
	if (py > 0 && check[px][py - 1] == 0 && cabbage[px][py - 1] == 1) {
		check[px][py - 1] = 1;
		dfs(px, py - 1, x_max, y_max);
	}
}

int main() {
	cin >> T;
	for (int i{ 0 }; i < T; i++) {
		cin >> M >> N >> K;
		memset(cabbage, 0, sizeof(cabbage));
		memset(check, 0, sizeof(check));
		answer = 0;
		for (int j{ 0 }; j < K; j++) {
			cin >> point_x >> point_y;
			cabbage[point_x][point_y] = 1;
		}
		for (int i{ 0 }; i < M; i++) {
			for (int j{ 0 }; j < N; j++) {
				if (cabbage[i][j] == 1 && check[i][j] == 0) {
					dfs(i, j, M-1, N-1);
					answer++;
				}
			}
		}
		cout << answer << endl;
	}
}