// Baekjoon 1300
// Binary Search

#include <iostream>

using namespace std;

long long int N, K;

void p_search(long long int left, long long int right) {
	long long mid, count, save, answer;
	while (left <= right) {
		long long mid = (left + right) / 2;
		count = 0;
		for (int i{ 0 }; i < N; i++) {
			save = mid / (i + 1);
			if (N > save)
				count += save;
			else
				count += N;
		}

		if (count < K) {
			left = mid + 1;
		}
		else {
			answer = mid;
			right = mid - 1;
		}
	}
	cout << answer << endl;
}

int main() {
	cin >> N >> K;
	p_search(1, K);
}
