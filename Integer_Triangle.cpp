#include <iostream>
#include <array>

using namespace std;

int n, save, n_max;

array<array<int, 501>, 501>numbers;

int main() {
	cin >> n;
	for (int i{ 0 }; i < n; i++) {
		for (int j{ 0 }; j < i+1; j++) {
			cin >> save;
			if (i == 0) {
				numbers[i][j] = save;
			}
			else {
				if (j==0) {
					numbers[i][j] = numbers[i - 1][j] + save;
				}
				else if (j == i) {
					numbers[i][j] = numbers[i - 1][j - 1] + save;
				}
				else {
					if (numbers[i - 1][j - 1] >= numbers[i-1][j]) {
						numbers[i][j] = numbers[i-1][j - 1] + save;
					}
					else {
						numbers[i][j] = numbers[i-1][j] + save;
					}
				}
				
			}
		}
	}
	n_max = numbers[n - 1][0];
	for (int i{ 1 }; i < n; i++) {
		if (n_max >= numbers[n-1][i]) {
		}
		else {
			n_max = numbers[n-1][i];
		}
	}

	cout << n_max << "\n";
}