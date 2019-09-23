#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n_count, save, num, answer;
string sig;

vector<int>sign;
vector<int>nums;

int main() {
	cin >> sig;
	sign.push_back(1);
	for (int i{ 0 }; i < sig.length(); i++) {
		if (sig[i] == '+' || sig[i] == '-') {
			num = 0;
			for (int j{ n_count }; j > 0; j--) {
				save = 1;
				if (n_count > 1) {
					for (int k{ 1 }; k < j; k++) {
						save *= 10;
					}
				}
				save *= sig[i - n_count] - 48;
			}
			num += save;
			if (sig[i] == '-') {
				sign.push_back(0);
			}
			else if (sig[i] == '+') {
				sign.push_back(1);
			}
			nums.push_back(num);
			n_count = 0;
		}
		else {
			n_count++;
		}
	}

	for (int i{ 0 }; i < nums.size(); i++) {
		if (sign[i] == 1) {
			answer += nums[i];
		}
		else if (sign[i] == 0) {
			answer -= nums[i];
		}
	}

	cout << answer << "\n";
}