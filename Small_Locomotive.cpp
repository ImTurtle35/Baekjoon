// Baekjoon 2616
// Dynamic Programming

#include <iostream>
#include <algorithm>

using namespace std;

int N, min_car;
int save_n;
int cus[50002];
int dp[4][50002];
int input;
int answer;

int main() {
	cin >> N;
	for (int i{ 1 }; i <= N; i++) {
		cin >> input;
		cus[i] = cus[i - 1] + input;
	}
	cin >> min_car;
	for (int i{ 1 }; i <= 3; i++) {
		for (int j{ i * min_car }; j <= N; j++) {
			dp[i][j] = max(dp[i][j - 1], dp[i-1][j - min_car] + cus[j] - cus[j - min_car]);
			answer = max(answer, dp[i][j]);
		}
	}
	cout << answer << endl;
}