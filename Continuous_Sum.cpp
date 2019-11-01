// Baekjoon 1912
// Dynamic Programming

#include <iostream>
#include <vector>

using namespace std;

int n, max_sum, save, number, max_min{ -1000 };
bool not_minus = false;

int main() {
	cin >> n;
	for (int i{ 0 }; i < n; i++) {
		cin >> number;
		if (number >= 0) {
			not_minus = true;
		}
		else {
			if (number > max_min)
				max_min = number;
		}
		save += number;
		if (save > max_sum)
			max_sum = save;
		if (save < 0) {
			save = 0;
		}
	}
	if (not_minus == true)
		cout << max_sum << endl;
	else
		cout << max_min << endl;
}