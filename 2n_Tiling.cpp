// Baekjoon 11726
// Dynamic Programming

#include <iostream>

using namespace std;

int arr[1001];

int rec(int n) {
	if (arr[n] != 0) return arr[n];
	if (n == 0)return 0;
	else if (n == 1) return 1;
	else if (n == 2) return 2;
	else {
		arr[n] = (rec(n - 1) + rec(n - 2)) % 10007;
		return arr[n];
	}
}

int main() {
	int N;
	cin >> N;
	cout << rec(N) << "\n";
}