// Baekjoon 3020
// Binary Search

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, H, input, l_count, sum, ans;
vector<int>Top;
vector<int>Bottom;

int Top_search(int left, int right, int high) {
	int mid, answer{ N/2 };
	while (left <= right) {
		mid = (left + right) / 2;
		if (Top[mid] < high) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
			if (answer > mid)
				answer = mid;
		}
	}
	return (N/2)-answer;
}

int Bot_search(int left, int right, int high) {
	int mid, answer{ N/2 };
	while (left <= right) {
		mid = (left + right) / 2;
		if (Bottom[mid] < high) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
			if (answer > mid)
				answer = mid;
		}
	}
	return (N / 2) - answer;
}

int main() {
	cin >> N >> H;
	for (int i{ 0 }; i < N; i++) {
		cin >> input;
		if (i % 2 == 0) {
			Bottom.push_back(input);
		}
		else
			Top.push_back(input);
	}

	sort(Bottom.begin(), Bottom.end());
	sort(Top.begin(), Top.end());
	ans = N + 1;

	for (int i{ 1 }; i <= H; i++) {
		sum = Top_search(0, (N / 2) - 1, H-i +1) + Bot_search(0, (N / 2) - 1, i);
		if (ans > sum) {
			ans = sum;
			l_count = 1;
		}
		else if (ans == sum)
			l_count++;
	}

	cout << ans << " " << l_count << endl;
}