// Baekjoon 2579
// Dynamic Programming

#include <iostream>
#include <array>
using namespace std;

array<int, 301> stairs;
array<array<int, 2>, 301> stairsave;

int number;
int save;
int comp(int a, int b) {
	int m;
	if (a >= b) m = a;
	else m = b;
	return m;
}

int main() {
	cin >> number;
	for (int i{ 0 }; i < number; i++) {
		cin >> stairs[i];
	}
	for (int i{ 0 }; i < number; i++) {
		if (i == 0)
			stairsave[i][1] = stairs[i];
		else if (i == 1) {
			stairsave[i][0] = stairsave[i - 1][1] + stairs[i];
			stairsave[i][1] = stairs[i];
		}
		else {
			stairsave[i][0] = stairsave[i - 1][1] + stairs[i];
			stairsave[i][1] = stairsave[i - 2][1] + stairs[i];
			save = stairsave[i - 2][0] + stairs[i];
			if (save > stairsave[i][1])
				stairsave[i][1] = save;
		}
	}
	cout << comp(stairsave[number-1][0], stairsave[number-1][1]) << "\n";
}