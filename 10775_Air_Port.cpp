// Baekjoon 10775

#include <iostream>
#include <vector>

using namespace std;

int G, P, input, answer;

struct Disjointset {
	vector<int>par;
	Disjointset(int n){
		par.resize(n + 2, -1);
	}
	int f(int v) {
		if (par[v] == -1) return v;
		return par[v] = f(par[v]);
	}
	void u(int a, int b) {
		a = f(a), b = f(b);
		if (a == b) return;
		else par[a] = b;
	}
};

int main() {
	cin >> G;
	cin >> P;
	Disjointset ds(G);
	for (int i{ 0 }; i < P; i++) {
		cin >> input;
		if (ds.f(input) == input) ds.par[input] = input - 1;
		else if (ds.f(input) == 0) break;
		else {
			while (ds.f(input) > 0) {
				ds.u(input, ds.f(input));
				if (ds.par[ds.f(input)] == -1) break;
			}
			if (ds.par[ds.f(input)] == -1) ds.par[ds.f(input)] = ds.f(input) - 1;
			else if (ds.f(input) == 0) break;
		}

		answer++;
	}
	cout << answer << endl;
}