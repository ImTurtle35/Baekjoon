// baekjoon 11729
#include <iostream>
#include <string>

using namespace std;

int N, start, elsw, dest;
int answer = 1;

void hanoi(int num, int start, int elsw, int dest) {
	if (num == 0)
		return;
	else {
		hanoi(num - 1, start, dest, elsw);
		cout << start << " " << dest << "\n";
		hanoi(num - 1, elsw, start, dest);
	}
}

int main() {
	cin >> N;
	for (int i{ 0 }; i < N; i++) {
		answer *= 2;
	}
	cout << answer - 1 << "\n";
	start = 1;
	elsw = 2;
	dest = 3;
	hanoi(N, start, elsw, dest);
}