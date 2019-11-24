// Baekjoon 6236
// Binary Search

#include <iostream>
#include <vector>

using namespace std;

bool tf;
int N, M, input, answer, sum;
vector<int>vec;

void p_search(int left, int right) {
	int mid, o_count, lm;
	while (left <= right) {
		mid = (left + right) / 2;
		o_count = 1;
		lm = mid;
		tf = true;
		for (int i{ 0 }; i < N; i++) {
			if (mid < vec[i]) {
				tf = false;
				break;
			}
			if (lm - vec[i] < 0) {
				lm = mid;
				o_count++;
			}
			lm -= vec[i];
		}
		if (o_count > M || tf == false) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
			answer = mid;
		}
	}
	cout << answer << endl;
}

int main() {
	cin >> N >> M;
	for (int i{ 0 }; i < N; i++) {
		cin >> input;
		vec.push_back(input);
		sum += input;
	}
	p_search(0, sum);
}