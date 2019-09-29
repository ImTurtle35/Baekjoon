// Algospot - JUMPGAME
#include <iostream>

using namespace std;

bool key;
int C, n, position, save;
int gameboard[101][101];

void possible(int x, int y, int e) {
	if (key == true)
		return;
	if (x > e || y > e) {
		return;
	}
	else {
		if (x == e && y == e) {
			key = true;
			return;
		}
		else {
			save = gameboard[x][y];
			possible(x + save, y, e);
			if (key == true)
				return;
			possible(x, y + save, e);
			if (key == true)
				return;
		}
	}
	return;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> C;
	for (int i{ 0 }; i < C; i++) {
		key = false;
		cin >> n;
		for (int j{ 0 }; j < n; j++) {
			for (int k{ 0 }; k < n; k++) {
				cin >> gameboard[j][k];
			}
		}
		possible(0, 0, n - 1);
		if (key == true) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}