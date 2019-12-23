// Baekjoon 1913

#include <iostream>

using namespace std;

int N, finding_n, n_save, x_save, y_save, x_pos, y_pos;
int snail[999][999];

void finding(int x_n, int y_n) {
	if (n_save == finding_n) {
		x_save = x_n, y_save = y_n;
	}
}

int main() {
	cin >> N >> finding_n;
	n_save = N * N;
	for (y_pos; y_pos < (N); y_pos++, n_save--) {
		snail[y_pos][x_pos] = n_save;
		finding(x_pos, y_pos);
	}
	y_pos--;
	for (int i{ (N) / 2 }; i > 0; i--) {
		for (int j{ x_pos + 1 }; j < x_pos + 2 * i + 1; j++,n_save--) {
			snail[y_pos][j] = n_save;
			finding(j, y_pos);
		}
		x_pos += 2 * i;
		for (int j{ y_pos - 1 }; j > y_pos - 2 * i - 1; j--, n_save--) {
			snail[j][x_pos] = n_save;
			finding(x_pos, j);
		}
		y_pos -= 2 * i;
		for (int j{ x_pos - 1 }; j > x_pos - 2 * i - 1; j--, n_save--) {
			snail[y_pos][j] = n_save;
			finding(j, y_pos);
		}
		x_pos -= 2 * i;
		for (int j{ y_pos + 1 }; j < y_pos + 2 * i + 1; j++, n_save--) {
			snail[j][x_pos] = n_save;
			finding(x_pos, j);
		}
		y_pos += 2 * i;
	}

	for (int i{ 0 }; i < N; i++) {
		for (int j{ 0 }; j < N; j++) {
			cout << snail[i][j] << " ";
		}
		cout << "\n";
	}
	cout << x_save + 1 << " " << y_save + 1 << "\n";
}