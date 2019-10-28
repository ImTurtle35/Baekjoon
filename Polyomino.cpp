// Baekjoon 1343
// Greedy Algorithm
#include <iostream>
#include <string>

using namespace std;

string board;
unsigned int board_len;
int X_count;
string answer;

int main() {
	cin >> board;
	board_len = board.length();
	answer = board;
	for (int i{ 0 }; i < board_len; i++) {
		if (board[i] == '.') {
			if (X_count % 2 == 1) {
				cout << "-1\n";
				return 0;
			}
			else {
				while (X_count > 0) {
					if (X_count >= 4) {
						for (int j{ 0 }; j < 4; j++) {
							answer[i - X_count + j] = 'A';
						}
						X_count -= 4;
					}
					else {
						for (int j{ 0 }; j < 2; j++) {
							answer[i - X_count + j] = 'B';
						}
						X_count -= 2;
					}
				}
			}
			X_count = 0;
		}
		else if (board[i] == 'X') {
			X_count++;
		}
	}
	if (X_count % 2 == 1) {
		cout << "-1\n";
		return 0;
	}
	else {
		while (X_count > 0) {
			if (X_count >= 4) {
				for (int j{ 0 }; j < 4; j++) {
					answer[board_len - X_count + j] = 'A';
				}
				X_count -= 4;
			}
			else {
				for (int j{ 0 }; j < 2; j++) {
					answer[board_len - X_count + j] = 'B';
				}
				X_count -= 2;
			}
		}
	}
	cout << answer << "\n";
}