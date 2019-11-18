// Baekjoon 2178
// Queue, BFS

#include <iostream>
#include <queue>
#include <string>

using namespace std;

typedef struct node_t {
	int l_m;
	int p_x;
	int p_y;
}Node;

int N, M, X, Y, L, x_s, y_s, answer;
string input;
int maze[101][101];
int check[101][101];
queue<Node>que;
int x_c[4] = { -1, 1, 0, 0 };
int y_c[4] = { 0, 0, -1, 1 };

void bfs() {
	while (!que.empty()) {
		L = que.front().l_m;
		X = que.front().p_x;
		Y = que.front().p_y;
		que.pop();
		for (int i{ 0 }; i < 4; i++) {
			x_s = X + x_c[i];
			y_s = Y + y_c[i];
			if (x_s == M && y_s == N) {
				answer = L + 1;
				return;
			}
			else if (x_s > 0 && x_s <= M && y_s > 0 && y_s <= N && check[y_s][x_s] != 1) {
				if (maze[y_s][x_s] == 1) {
					que.push(Node{ L + 1, x_s, y_s });
					check[y_s][x_s] = 1;
				}
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i{ 1 }; i <= N; i++) {
		cin >> input;
		for (int j{ 1 }; j <= M; j++) {
			maze[i][j] = input[j - 1] - '0';
		}
	}
	que.push(Node{ 1,1,1 });
	check[1][1] = 1;
	bfs();
	cout << answer << endl;
}