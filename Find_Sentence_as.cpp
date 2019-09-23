#include <iostream>
#include <string>

using namespace std;

bool key, blank;
int M, N, n_count, len;
char book[1002][61];
char memo[10001][61];

int main() {
	cin >> M >> N;
	for (int i{ 0 }; i < M+1; i++) {
		cin.getline(book[i],61);
	}
	for (int i{ 0 }; i < N; i++) {
		cin.getline(memo[i], 61);
		for (int j{ 1 }; j < M+1; j++) {
			key = true;
			for (int k{ 0 }; k < 60; k++) {
				if (memo[i][k] == book[j][k]) {
					continue;
				}
				else if (memo[i][k] == ' ') {
					if (book[j][k] != ' ') {
						key = false;
						break;
					}
				}
			}
			if (key == true) {
				n_count++;
				break;
			}
		}

	}
	cout << n_count << "\n";
}