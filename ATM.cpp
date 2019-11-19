// Baekjoon 11399
// Greedy Algorithm
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, input_time, save, answer;
vector<int>P;

int main() {
	cin >> N;
	for (int i{ 0 }; i < N; i++) {
		cin >> input_time;
		P.push_back(input_time);
	}
	sort(P.begin(), P.end());
	for (int i{ 0 }; i < N; i++) {
		save += P[i];
		answer += save;
	}
	cout << answer << endl;
}