// baekjoon 1051
// algorithm sutdy - baekjoon
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M, save;
int answer = 1;
string num_row;
int matrix[50][50];

int main() {
	cin >> N >> M;
	for (int i{ 0 }; i < N; i++) {
		cin >> num_row;
		for (int j{ 0 }; j < M; j++) {
			matrix[i][j] = num_row[j] - 48;
		}
	}
	if (N >= M) {
		save = M;
	}
	else {
		save = N;
	}

	for (int i{ save-1 }; i > 0; i--) {
		for (int j{ 0 }; j < N-i; j++) {
			for (int k{ 0 }; k < M-i; k++) {
				if (matrix[j][k] == matrix[j][k + i] && matrix[j][k] == matrix[j+i][k]
					&& matrix[j][k] == matrix[j+i][k+i]) {
					cout << (i+1) * (i+1) << endl;
					return 0;
				}
			}
		}
	}

	cout << 1 << endl;
}