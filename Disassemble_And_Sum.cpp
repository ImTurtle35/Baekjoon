// baekjoon 2231
// algorithm study - brute force
#include <iostream>

using namespace std;

int N, con_min, save;

int main() {
	cin >> N;
	for (int i{ 1 }; i < N+1; i++) {
		save = i;
		save += i / 100000;
		save += (i % 100000) / 10000;
		save += (i % 10000) / 1000;
		save += (i % 1000) / 100;
		save += (i % 100) / 10;
		save += (i % 10);
		if (save == N) {
			cout << i << "\n";
			return 0;
		}
	}
	save = 0;
	cout << save << "\n";
}