// Algospot - JUMPGAME
#include <iostream>
#include <string>

using namespace std;

int C, n, position, save;
int gameboard[100][100];
int cache[100][100];

int possible(int x, int y, int e) {

	if (x == e -1 && y == e-1) {
		return 1;
	}

	if (x >= e || y >= e) {
		return 0;
	}

	if (cache[x][y] != -1) {
		return cache[x][y];
	}
	return cache[x][y] = (possible(x + gameboard[x][y], y, e)||possible(x, y + gameboard[x][y],e));
}

int main() {
	cin >> C;
	for (int i{ 0 }; i < C; i++) {
		cin >> n;
	
		for (int j{ 0 }; j < 100; j++) {
			for (int k{ 0 }; k < 100; k++) {
				cache[j][k] = -1;
			}
		}
		
		for (int j{ 0 }; j < n; j++) {
			for (int k{ 0 }; k < n; k++) {
				cin >> gameboard[j][k];
			}
		}
		if (possible(0, 0, n) == 1) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}