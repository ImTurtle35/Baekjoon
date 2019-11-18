// baekjoon 10263
// greedy algorithm
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, block, answer, save, charge;
vector<int>building;

bool comp(int a, int b) {
	if (a < b) return true;
	else return false;
}

int main() {
	cin >> N;
	for (int i{ 0 }; i < N; i++) {
		cin >> block;
		building.push_back(block);
	}
	sort(building.begin(), building.end());
	save = N;
	for (int i{ 0 }; i < N; i++) {
		save = min(save, building[i] + N - i - 1);
	}
    cout << save << endl;
}