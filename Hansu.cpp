#include <iostream>

using namespace std;

int N, count_n, mid, top, bot;

int main() {
	cin >> N;
	for (int i{ 1 }; i <= N; i++) {
		if (i < 100)
			count_n++;
		else if (i == 1000)
			break;
		else {
			top = i / 100;
			mid = (i / 10) % 10;
			bot = i % 10;
			if (mid - top == bot - mid) {
				count_n++;
			}
		}
	}
	cout << count_n << "\n";
}