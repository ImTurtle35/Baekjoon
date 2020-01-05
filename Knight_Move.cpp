// Baekjoon 7562
// BFS

#include <iostream>
#include <queue>

using namespace std;

typedef struct node_t {
	int order;
	int x_pos;
	int y_pos;
}Node;

int chess[301][301];
int T, I,X,Y,O,X_save,Y_save,answer;
int start_pos[2];
int end_pos[2];
int X_cal[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
int Y_cal[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
queue<Node>que;

int bfs() {
	while (!que.empty()) {
		O = que.front().order;
		Y = que.front().y_pos;
		X = que.front().x_pos;
		que.pop();
		if (Y == end_pos[1] && X == end_pos[0]) {
			return O;
		}

		for (int i{ 0 }; i < 8; i++) {
			X_save = X + X_cal[i];
			Y_save = Y + Y_cal[i];
			if (X_save >= 0 && X_save < I && Y_save >= 0 && Y_save < I) {
				if (chess[X_save][Y_save] == 0) {
					chess[X_save][Y_save] = 1;
					que.push(Node{ O + 1, X_save, Y_save });
				}
			}
		}
		
	}
	return O;
}

int main() {
	cin >> T;
	for (int i{ 0 }; i < T; i++) {
		for (int j{ 0 }; j <= 300; j++) {
			for (int k{ 0 }; k <= 300; k++) {
				chess[j][k] = 0;
			}
		}
		while (!que.empty()) {
			que.pop();
		}
		cin >> I;
		cin >> start_pos[0] >> start_pos[1];
		cin >> end_pos[0] >> end_pos[1];
		que.push(Node{ 0, start_pos[0], start_pos[1] });
		cout << bfs() << endl;
	}
}