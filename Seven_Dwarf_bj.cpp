// baekjoon 2309
// Brute Force
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int save, height;
int sum;
vector<int>before;
vector<int>v_select;
vector<int>after;

void next_per_combination(int k) {
	for (int i = 0; i < k; i++) {
		v_select.push_back(1);
	}
	for (int i = 0; i < before.size() - k; i++) {
		v_select.push_back(0);
	}
	sort(v_select.begin(), v_select.end());
	do {
		save = 0;
		for (int i = 0; i < before.size(); i++) {
			if (v_select[i] == 1)
				save += before[i];
		}
		if (save + 100 == sum) {
			for (int i = 0; i < before.size(); i++) {
				if (v_select[i] == 0)
					after.push_back(before[i]);
				
			}
			break;
		}
	} while (next_permutation(v_select.begin(), v_select.end()));
}

int main() {
	for (int i{ 0 }; i < 9; i++) {
		cin >> height;
		before.push_back(height);
		sum += before[i];
	}
	next_per_combination(2);
	
	sort(after.begin(), after.end());
	for (int i{ 0 }; i < 7; i++) {
		cout << after[i] << "\n";
	}
}