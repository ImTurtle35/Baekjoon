// Baekjoon 15900
// BFS & DFS

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <array>

using namespace std;
typedef struct Node {
	vector<int>store;
	int stair = 0;
	bool tf = false;
	bool key = false;
}node_t;
vector<int>store;
array<node_t, 500001>tree;
stack<node_t>sta;
int N, a, b,tree_count,cur,answer;

void bfs(int n, int s) {
	int count = 0;
	int save;
	tree[n].stair = s;
	while (count < tree[n].store.size()) {
		save = tree[n].store[count];
		count++;
		if (tree[save].tf == true)
			continue;
		else {
			tree[n].key = true;
			tree[save].tf = true;
			bfs(save, s + 1);
		}
	}
	if (tree[n].key == false)
		answer += tree[n].stair;
}

int main() {
	cin >> N;
	for (int i{ 1 }; i < N; i++) {
		cin >> a >> b;
		tree[a].store.push_back(b);
		tree[b].store.push_back(a);
	}
	tree[1].tf = true;
	bfs(1, 0);
	if (answer % 2 == 0) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}
}
