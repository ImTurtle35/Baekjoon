// Baekjoon 16288
// Greedy Algorithm
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool YN;
int N, K, e_n, c_pos, save;
vector<int>e_o;
int arr[101];

int main() {
	cin >> N >> K;
	for (int i{ 0 }; i < N; i++) {
		cin >> e_n;
		e_o.push_back(e_n);
	}
	for (int i{ 0 }; i < N; i++) {
		YN = true;
		save = e_o[i];
		for (int j{ 0 }; j < K; j++) {
			if (arr[j] > save) {
				YN = false;
			}
			else {
				YN = true;
				arr[j] = save;
				break;
			}
		}
		if (YN == false) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	
}