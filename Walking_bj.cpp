// baekjoon 1459
// greedy algorithm
#include <iostream>

using namespace std;

int X, Y, W, S, path_a, path_b, big, small;

int main() {
	cin >> X >> Y >> W >> S;
	if (X >= Y)
		big = X, small = Y;
	else
		small = X, big = Y;
	if (W*2 >= S) {
		cout << small * S + (big - small) * W;
	}
	else {
		cout << (small + big) * W;
	}
}