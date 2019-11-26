// Baekjoon 2343
// Binary Search
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int N, M, input, max_blueray, max_time;
vector<long long int>lesson;

void p_search(long long int left, long long int right) {
	long long int mid, br_len, br_count;
	while (left <= right) {
		mid = (left + right) / 2;
		br_len = 0;
		br_count = 1;
		for (long long int i{ 0 }; i < N; i++) {
			if (br_len + lesson[i] > mid) {
				br_len = lesson[i];
				br_count++;
			}
			else {
				br_len += lesson[i];
			}
		}
		if (br_count > M) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << left << endl;
}

int main() {
	cin >> N >> M;
	for (long long int i{ 0 }; i < N; i++) {
		cin >> input;
		lesson.push_back(input);
		max_blueray += input;
		if (input > max_time) {
			max_time = input;
		}
	}
	p_search(max_time, max_blueray);
}