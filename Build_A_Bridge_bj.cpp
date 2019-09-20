#include <iostream>
#include <vector>

using namespace std;

int T, N, M, result;

// 조합을 사용
// 조합 일반식을 사용하면 int값 초과
// 모든 조합을 (nCr = n-1Cr + n-1Cr-1)로 구현하면 시간 초과
// 낮은 값은 일반식으로 계산 후 합으로 구현

int nCr(int M, int N) {
	int rn, a;
	rn = 1;
	a = M;
	if (N == 0 || M == N) {
		return 1;
	}
	else {
		if (M < 10) {
			for (int i{ 0 }; i < N; i++) {
				rn *= a;
				a--;
			}
			for (int i{ 0 }; i < N; i++) {
				rn /= i + 1;
			}
			return rn;
		}
		else
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