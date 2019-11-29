// Baekjoon 15732
// Binary Search

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct Node {
	long long int A, B, C;
}rule;

vector<rule>rules;

long long int N, K, D, A, B, C;

void p_search(int left, int right) {
	long long int mid, count, answer;
	while (left <= right) {
		mid = (left + right) / 2;
		count = 0;
		for (long long int i{ 0 }; i < K; i++) {
			if (mid < rules[i].A) {
				continue;
			}
			if (mid >= rules[i].B) {
				count += ((rules[i].B - rules[i].A) / rules[i].C) + 1;
			}
			else {
				count += ((mid - rules[i].A) / rules[i].C) + 1;
			}
		}
		if (count >= D) {
			right = mid - 1;
			answer = mid;
		}
		else {
			left = mid + 1;
		}
	}
	cout << answer << endl;
}

int main() {
	cin >> N >> K >> D;
	for (long long int i{ 0 }; i < K; i++) {
		cin >> A >> B >> C;
		rule newrule{ A,B,C };
		rules.push_back(newrule);
	}

	p_search(1, N);
}