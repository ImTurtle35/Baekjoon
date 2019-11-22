// Baekjoon 2805
// Bineary Search
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int N, M, input;
vector<long long int>tree;

void bfs(int left, int right) {
	long long int mid, save, answer;
	answer = 0;
	while (left <= right) {
		save = 0;
		mid = (left + right) / 2;
		for (int i{ 0 }; i < N; i++) {
			if (mid < tree[i])
				save += (tree[i] - mid);
		}
		if (save < M) {
			right = mid - 1;
		}
		else {
			if (answer < mid) {
				left = mid + 1;
				answer = mid;
			}
			else {
				if (mid == 0) {
					save = 0;
					for (int i{ 0 }; i < N; i++) {
						if (1 < tree[i])
							save += (tree[i] - 1);
					}
					if (save >= M) {
						answer = 1;
						break;
					}
					else
						right = mid - 1;
				}
				else 
				right = mid - 1;
			}
		}
	}
	cout << answer << endl;
}

int main() {
	cin >> N >> M;
	for (int i{ 0 }; i < N; i++) {
		cin >> input;
		tree.push_back(input);
	}
	sort(tree.begin(), tree.end());
	bfs(0, tree[N - 1]);
}