#include <iostream>
#include <vector>

using namespace std;

int T, N, M, result;

// ������ ���
// ���� �Ϲݽ��� ����ϸ� int�� �ʰ�
// ��� ������ (nCr = n-1Cr + n-1Cr-1)�� �����ϸ� �ð� �ʰ�
// ���� ���� �Ϲݽ����� ��� �� ������ ����

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