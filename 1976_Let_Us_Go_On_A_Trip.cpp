// Baekjoon 1976

#include <iostream>
#include <vector>

using namespace std;

int N, M, input, save;

struct DisjointSet {
	vector<int>par;
	DisjointSet(int n) {
		par.resize(n + 2, -1);
	}
	int f(int v) {
		if (par[v] == -1) return v;
		return par[v] = f(par[v]);
	}
	void u(int x, int y) {
		x = f(x), y = f(y);
		if (x == y) return;
		par[x] = y;
	}
};

int main() {
	cin.tie();
	ios::sync_with_stdio(false);
	cin >> N;
	cin >> M;
	DisjointSet ds(N);
	for (int i{ 1 }; i <= N; i++) {
		for (int j{ 1 }; j <= N; j++) {
			cin >> input;
			if (input == 1) ds.u(i, j);
		}
	}
	cin >> input;
	save = ds.f(input);
	for (int i{ 1 }; i < M; i++) {
		cin >> input;
		if (save != ds.f(input)) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}