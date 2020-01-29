// Baekjoon 1717
// Disjoint-Set

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, m, a, b;
int uf;
struct DisjointSet {
	vector<int>par;
	DisjointSet(int a) {
		par.resize(a+1, -1);
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
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	DisjointSet ds(n);
	for (int i{ 0 }; i < m; i++) {
		cin >> uf >> a >> b;
		if (uf == 0) ds.u(a, b);
		else if (uf == 1) {
			if (ds.f(a) == ds.f(b))
				cout << "YES\n";
			else cout << "NO\n";
		}
	}
}