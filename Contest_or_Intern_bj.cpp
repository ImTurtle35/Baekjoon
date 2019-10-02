// baekjoon 2875
// Greedy Algorithm
#include <iostream>

using namespace std;

int N, M, K, save, need_minus, answer;

int main() {
	cin >> N >> M >> K;
	for (int i{ 0 }; i < K; i++) {
		if (N >= 2 * M)
			N--;
		else
			M--;
	}
	if (N >= 2 * M)
		answer = M;
	else
		answer = N/2;
	cout <<  answer;
}