// Baekjoon 1915
// Dynamic Programming

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;
int N, M, answer;
int board[1001][1001];
int save[1001][1001];

int main() {
	scanf("%d %d", &N, &M);
	for (int i{ 1 }; i <= N; i++) {
		for (int j{ 1 }; j <= M; j++) {;
		scanf("%1d", &board[i][j]);
		}
	}
	for (int i{ 1 }; i <= N; i++) {
		for (int j{ 1 }; j <= M; j++) {
			if (board[i][j] == 0) {
				save[i][j] = 0;
			}
			else if (board[i][j] == 1) {
				save[i][j] = min(min(save[i - 1][j], save[i][j - 1]), save[i - 1][j - 1]) + 1;
				answer = max(answer, save[i][j]);
			}
		}
	}
	
	printf("%d\n", answer * answer);
}