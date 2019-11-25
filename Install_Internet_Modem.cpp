// Baekjoon 2110
// Binary Search

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C, input;
vector<int>house;
vector<int>gap;

void p_search(int left, int right) {
	int mid , gap_save, im_count, answer;
	while (left <= right) {
		mid = (left + right) / 2;
		gap_save = 0;
		im_count = 1;
		for (int i{ 0 }; i < N - 1; i++) {
			if (gap_save + gap[i] >= mid) {
				gap_save = 0;
				im_count++;
			}
			else {
				gap_save += gap[i];
			}
		}
		if (im_count >= C) {
			left = mid + 1;
			answer = mid;
		}
		else {
			right = mid - 1;
		}
	}
	cout << answer << endl;
}

int main() {
	cin >> N >> C;
	for (int i{ 0 }; i < N; i++) {
		cin >> input;
		house.push_back(input);
	}
	sort(house.begin(), house.end());
	for (int i{ 0 }; i < N - 1; i++) {
		gap.push_back(house[i + 1] - house[i]);
	}
	p_search(1, house[N-1] - house[0]);
}
