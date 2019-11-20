// Baekjoon 2583
// DFS or BFS

#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct node_t {
	int x_pos;
	int y_pos;
}Node;

int M, N, K, X_pos1, X_pos2, Y_pos1, Y_pos2;
int black[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<int>answer;
queue<Node>que;

void bfs() {
	int a_count = 1;
	while (!que.empty()) {
		int x_cur = que.front().x_pos;
		int y_cur = que.front().y_pos;
		que.pop();
		for (int i{ 0 }; i < 4; i++) {
			int x_save = x_cur + dx[i];
			int y_save = y_cur + dy[i];
			if (x_save > 0 && x_save <= N && y_save > 0 && y_save <= M) {
				if (black[y_save][x_save] == 0){
					black[y_save][x_save] = 1;
					que.push(Node{ x_save, y_save });
					a_count++;
				}
			}
		}
	}
	answer.push_back(a_count);
}

int main() {
	cin >> M >> N >> K;
	for (int i{ 0 }; i < K; i++) {
		cin >> X_pos1 >> Y_pos1 >> X_pos2 >> Y_pos2;
		for (int j{ 1 }; j <= Y_pos2 - Y_pos1; j++) {
			for (int k{ 1 }; k <= X_pos2 - X_pos1; k++) {
				black[Y_pos1 + j][X_pos1 + k] = 1;
			}
		}
	}
	for (int i{ 1 }; i <= N; i++) {
		for (int j{ 1 }; j <= M; j++) {
			if (black[j][i] == 0) {
				black[j][i] = 1;
				que.push(Node{ i,j });
				bfs();
			}
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << endl;
	for (int i{ 0 }; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
}