// Baekjoon 11404
// Floyd-Warshall Algorithm

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 100001;
int n, m, a, b, c;
int doshi[101][101];

int main() {
	cin >> n;
	cin >> m;
	for (int i{ 0 }; i < n+1; i++) {
		for (int j{ 0 }; j < n+1; j++) {
			doshi[i][j] = INF;
		}
	}
	for (int i{ 0 }; i < m; i++) {
		cin >> a >> b >> c;
		if (doshi[a][b] < INF) {
			if (doshi[a][b] <= c)
				continue;
		}
		doshi[a][b] = c;
	}
	for (int k{ 1 }; k < n+1; k++) {
		for (int i{ 1 }; i < n + 1; i++) {
			for (int j{ 1 }; j < n+1; j++) {
				doshi[i][j] = min(doshi[i][j], doshi[i][k] + doshi[k][j]);
			}
		}
	}
	for (int i{ 1 }; i < n+1; i++) {
		for (int j{ 1 }; j < n+1; j++) {
			if (doshi[i][j] >= INF || i == j) {
				cout << 0 << " ";
			}
			else {
				cout << doshi[i][j] << " ";
			}
		}
		cout << endl;
	}
}