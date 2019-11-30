// Baekjoon 2613
// Binary Search

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 999;
int N, M, input, sum_max, sum_save, n_count, g_count;
vector<int>beads;
vector<int>b_group;

int p_search(int left, int right) {
	bool key;
	int mid, count, n_sum;
	while (left <= right) {
		key = 1;
		mid = (left + right) / 2;
		count = 1;
		n_sum = 0;
		for (int i{ 0 }; i < N; i++) {
			if (beads[i] > mid) {
				key = 0;
				break;
			}
			n_sum += beads[i];
			if (n_sum > mid) {
				count++;
				n_sum = beads[i];
			}
		}
		if (count > M || key == 0) {
			left = mid + 1;
		}
		else {
			right = mid-1;
			if (mid < answer)
				answer = mid;
		}
	}
	return answer;
}

void g_match(int answer) {
	int count{ 0 }, n_sum{ 0 };
	for (int i{ 0 }; i < N; i++) {
		if (n_sum + beads[i] > answer) {
			b_group.push_back(count);
			n_sum = beads[i];
			count = 1;
		}
		else {
			n_sum += beads[i];
			count++;
		}
	}
	b_group.push_back(count);

	int gap_save = M - b_group.size();
	if (gap_save == 0) {
		for (int i{ 0 }; i < b_group.size(); i++) {
			cout << b_group[i] << " ";
		}
	}
	else {
		int size = b_group.size();
		for (int i = 0; i < size; i++) {
			if (b_group[i] == 1)
				continue;
			else if (gap_save > 0) {
				b_group.push_back(1);
				b_group[i]--; i--; gap_save--;
			}
		}
		// sort(b_group.begin(), b_group.end());
		for (int i = b_group.size() - 1; i >= 0; i--) {
			cout << b_group[i] << " ";
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i{ 0 }; i < N; i++) {
		cin >> input;
		beads.push_back(input);
	}
	answer = p_search(1, 100 * N);
	cout << answer << endl;
	g_match(answer);
}