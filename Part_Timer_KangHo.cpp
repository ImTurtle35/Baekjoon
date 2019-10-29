// Baekjoon 1758
// Greedy Algorithm

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int save;
long long int answer;
vector<int>tip;

bool tmp(int a, int b) {
	if (a > b)
		return true;
	else
		return false;
}

int main() {
	cin >> N;
	for (int i{ 0 }; i < N; i++) {
		cin >> save;
		tip.push_back(save);
	}
	sort(tip.begin(), tip.end(), tmp);
	for (int i{ 0 }; i < N; i++) {
		if (tip[i] > i) {
			answer += (tip[i] - i);
		}
		else
			break;
	}
	cout << answer << "\n";
}