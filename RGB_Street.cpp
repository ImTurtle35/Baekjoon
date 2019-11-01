// Baekjoon 1149
// Dynamic Programming

#include <iostream>

using namespace std;

int N, R, G, B;
int RGB[3];
int save[3];

int comp(int a, int b) {
	if (a < b) return a;
	else return b;
}

int main() {
	cin >> N;
	for (int i{ 0 }; i < N; i++) {
		cin >> R >> G >> B;
		if (i == 0) {
			RGB[0] = R; RGB[1] = G; RGB[2] = B;
			save[0] = R; save[1] = G; save[2] = B;
		}
		else {
			RGB[0] = comp(save[1], save[2]) + R;
			RGB[1] = comp(save[0], save[2]) + G;
			RGB[2] = comp(save[0], save[1]) + B;
			save[0] = RGB[0], save[1] = RGB[1], save[2] = RGB[2];
		}
	}
	cout << comp(RGB[0], comp(RGB[1], RGB[2]));
}