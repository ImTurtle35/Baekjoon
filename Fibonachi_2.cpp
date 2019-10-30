// Baekjoon 2748
// Dynamic Programming

#include <iostream>

using namespace std;

long long int dp[1000];
int number;
long long int fibonachi(int n) {
	if (dp[n] != 0)
		return dp[n];
	if (n == 0) {
		return 0;
	}
	else if (n == 1) {
		return 1;
	}
	else {
		dp[n] = fibonachi(n - 1) + fibonachi(n - 2);
		return dp[n];
	}

}

int main() {
	cin >> number;
	cout << fibonachi(number) << "\n";
}