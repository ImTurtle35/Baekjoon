// Baekjoon 10250
#include <iostream>
#include <iomanip>

using namespace std;

int T, H, W, N;

int main() {
	cin.tie();
	ios::sync_with_stdio(false);
	cin >> T;
	for (int i{ 0 }; i < T; i++) {
		cin >> H >> W >> N;
		if (N % H == 0) cout << H << setw(2) << setfill('0') << (N / H) << "\n";
		else cout << N % H << setw(2) << setfill('0') << (N / H) + 1 << "\n";
	}
}