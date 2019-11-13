// Baekjoon 1260
// Stack, Queue, DFS, BFS
#include <iostream>
#include <stack>
#include <cstring>
#include <queue>

using namespace std;

stack<int>sta;
queue<int>que;
int save[1001][1001];
int check[1001];
int N, M, V, num1, num2, now;

void dfs(int num) {
	sta.push(num);
	cout << num << ' ';
	check[num] = true;
	while (!sta.empty()) {
		now = sta.top();
		for (int i{ 1 }; i <= N; i++) {
			if (check[i] || !save[now][i])continue;
			check[i] = true;
			sta.push(i);
			cout << i << ' ';
			break;
		}
		if (sta.top() == now) {
			sta.pop();
		}
	}
}
void bfs(int num) {
	que.push(num);
	check[num] = true;
	while (!que.empty()) {
		now = que.front();
		que.pop();
		cout << now << ' ';
		for (int i{ 1 }; i <= N; i++) {
			if (check[i] || !save[now][i])continue;
			check[i] = true;
			que.push(i);
		}
	}
}

int main() {
	cin >> N >> M >> V;
	for (int i{ 0 }; i < M; i++) {
		cin >> num1 >> num2;
		save[num1][num2] = 1;
		save[num2][num1] = 1;
	}
	dfs(V);
	cout << "\n";
	memset(check, 0, sizeof(check));
	bfs(V);
	cout << "\n";
}