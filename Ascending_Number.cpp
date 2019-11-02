// Baekjoon 11057
// Dynamic Programming

#include <iostream>

using namespace std;

int save[1001][10];
int N, answer;

int main() {
	cin >> N;
	for (int i{ 0 }; i < N; i++) {
		if (i == 0) {
			for (int j{ 0 }; j < 10; j++) {
				save[i][j] = j + 1;
			}
		}
		else {
			for (int j{ 0 }; j < 10; j++) {
				if (j == 0)
					save[i][j] = save[i - 1][j];
				else
					save[i][j] = (save[i][j - 1] + save[i - 1][j]) % 10007;
			}
		}
	}
	cout << save[N - 1][9];
}