#include <iostream>
#include <vector>

using namespace std;

int T, N, M, result;

int nCr(int M, int N) {
	if (N == 0 || M == N) {
		return 1;
	}
	else {
		return nCr(M - 1, N) + nCr(M - 1, N - 1);
	}
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		result = 0;
		cin >> N >> M;
		result = nCr(M, N);
		cout << result << "\n";
	}
}