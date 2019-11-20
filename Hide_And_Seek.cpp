// Baekjoon 1697
// BFS and DFS
// Á¾¸¸ºÏ
#include <iostream>
#include <queue>
using namespace std;

int N, K, X_cur, s_cur, X_save;

bool visit[150000];
typedef struct node_t {
	int x_pos;
	int sec;
} Node;
int cal[2] = { 1, -1 };
queue<Node>que;

void bfs() {
	while (!que.empty()) {
		X_cur = que.front().x_pos;
		s_cur = que.front().sec;
		que.pop();
		for (int i{ 0 }; i < 3; i++) {
			if (i < 2)
				X_save = X_cur + cal[i];
			else if (i == 2)
				X_save = X_cur * 2;
			if (X_save >= 0 && X_save < 150000) {
				if (X_save == K) {
					cout << s_cur + 1 << endl;
					return;
				}
				else if (visit[X_save] == 0) {
					visit[X_save] = 1;
					que.push(Node{ X_save, s_cur + 1 });
				}
			}
		}
	}
}

int main() {
	cin >> N >> K;
	if (N == K) {
		cout << 0 << endl;
		return 0;
	}
	que.push(Node{ N, 0 });
	visit[N] = 1;
	bfs();
}