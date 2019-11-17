// Baekjoon(7576)
// Queue, BFS

#include <iostream>
#include <queue>

using namespace std;

typedef struct node_t {
	int date;
	int x_pos;
	int y_pos;
}Node;

int M, N, answer, X, Y, D, X_save, Y_save;
int tomato[1001][1001];
int check_que[1001][1001];
int X_cal[4] = { -1, 1, 0, 0 };
int Y_cal[4] = { 0, 0, -1, 1 };
bool not_only_zero = false;
queue<Node>que;

void bfs() {
	while (!que.empty()) {
		D = que.front().date;
		Y = que.front().y_pos;
		X = que.front().x_pos;
		que.pop();

		for (int i{ 0 }; i < 4; i++) {
			X_save = X + X_cal[i];
			Y_save = Y + Y_cal[i];
			if (X_save > 0 && X_save <= N && Y_save > 0 && Y_save <= M) {
				if (tomato[X_save][Y_save] == 0) {
					tomato[X_save][Y_save] = 1;
					que.push(Node{ D + 1, X_save, Y_save });
				}
			}
		}
		answer = D;
	}
}

int main() {
	cin >> M >> N;
	for (int i{ 1 }; i <= N; i++) {
		for (int j{ 1 }; j <= M; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				que.push(Node{ 0,i,j });
				not_only_zero = true;
			}
		}
	}
	if (not_only_zero == false) {
		cout << 0 << endl;
		return 0;
	}
	else {
		bfs();
	}
	for (int i{ 1 }; i <= N; i++) {
		for (int j{ 1 }; j <= M; j++) {
			if (tomato[i][j] == 0) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << answer << endl;
}