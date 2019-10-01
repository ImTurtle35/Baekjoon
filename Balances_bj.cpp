// baekjoon (2437)
// greedy algorithm
#include <iostream>
#include <algorithm>

using namespace std;

int N, n_save;
int chu[1000];

int main() {
	cin >> N;
	for (int i{ 0 }; i < N; i++) {
		cin >> chu[i];
	}

	sort(chu, chu + N);

	n_save = 1;

	for (int i{ 0 }; i < N; i++) {
		if (n_save < chu[i]) {
			break;
		}
		n_save += chu[i];
	}

	cout << n_save;
}