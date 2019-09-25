// baekjoon 2309
// Brute Force
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int save1, save2, n_count;
int sum;
int before[9];
int after[7];

int main() {
	for (int i{ 0 }; i < 9; i++) {
		cin >> before[i];
		sum += before[i];
	}
	for (int i{ 0 }; i < 9; i++) {
		for (int j{ i + 1 }; j < 9; j++) {
			if (sum - (before[i] + before[j]) == 100) {
				save1 = i;
				save2 = j;
				break;
			}
		}
	}
	for (int i{ 0 }; i < 9; i++) {
		if (i != save1 && i != save2) {
			after[n_count] = before[i];
			n_count++;
		}
	}
	sort(after, after+7);
	for (int i{ 0 }; i < 7; i++) {
		cout << after[i] << "\n";
	}
}