// Baekjoon 2512
// Bineary Search
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, input, budget, avg, save, answer, sum;
vector<int>vec;

void p_search(int left, int right) {
	int mid;
	while (left <= right) {
		mid = (left + right) / 2;
		save = 0;
		for (int i{ 0 }; i < N; i++) {
			if (mid >= vec[i])
				save += vec[i];
			else {
				
				save += mid;
			}
		}
		if (save > budget) {
			right = mid - 1;
		}
		else {
			if (mid > vec[N - 1]) {
				right = mid - 1;
				answer = vec[N - 1];
			}
			else {
				left = mid + 1;
				answer = mid;
			}
		}
	}
	cout << answer << endl;
}

int main() {
	cin >> N;
	for (int i{ 0 }; i < N; i++) {
		cin >> input;
		vec.push_back(input);
		sum += input;
	}
	cin >> budget;
	sort(vec.begin(), vec.end());
	p_search(0, budget);
}