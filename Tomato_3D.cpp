// Baekjoon(7569)
// Queue, BFS

#include <iostream>
#include <queue>

using namespace std;

typedef struct node_t {
	int date;
	int x_pos;
	int y_pos;
	int z_pos;
}Node;

int M, N, H, answer, X, Y, Z, D, X_save, Y_save, Z_save;
int tomato[101][101][101];
int check_que[101][101][101];
int X_cal[6] = { -1, 1, 0, 0, 0, 0 };
int Y_cal[6] = { 0, 0, -1, 1, 0 , 0 };
int Z_cal[6] = { 0, 0, 0, 0, -1, 1 };
bool not_only_zero = false;
queue<Node>que;

void bfs() {
	while (!que.empty()) {
		D = que.front().date;
		Y = que.front().y_pos;
		X = que.front().x_pos;
		Z = que.front().z_pos;
		que.pop();
		for (int i{ 0 }; i < 6; i++) {
			X_save = X + X_cal[i];
			Y_save = Y + Y_cal[i];
			Z_save = Z + Z_cal[i];
			if (X_save > 0 && X_save <= M && Y_save > 0 && Y_save <= N &&
				Z_save > 0 && Z_save <= H) {
				if (tomato[Z_save][Y_save][X_save] == 0) {
					tomato[Z_save][Y_save][X_save] = 1;
					que.push(Node{ D + 1, X_save, Y_save, Z_save });
				}
			}
		}
		answer = D;
	}
}

int main() {
	cin >> M >> N >> H;
	for (int i{ 1 }; i <= H; i++) {
		for (int j{ 1 }; j <= N; j++) {
			for (int k{ 1 }; k <= M; k++) {
				cin >> tomato[i][j][k];
				if (tomato[i][j][k] == 1) {
					que.push(Node{ 0,k,j,i });
					not_only_zero = true;
				}
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
	for (int i{ 1 }; i <= H; i++) {
		for (int j{ 1 }; j <= N; j++) {
			for (int k{ 1 }; k <= M; k++) {
				if (tomato[i][j][k] == 0) {
					cout << -1 << endl;
					return 0;
				}
			}
		}
	}
	cout << answer << endl;
}