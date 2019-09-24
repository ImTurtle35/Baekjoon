#include <iostream>
#include <string>
#include <vector>

using namespace std;

int num, answer, sum, savepoint, n_count;
string sig;

vector<int>sign;
vector<int>nums;

int main() {
	cin >> sig;
	sign.push_back(1);
	for (int i{ 0 }; i < sig.length(); i++) {
		if (sig[i] == '+' || sig[i] == '-') {
			
			nums.push_back(num);
			num = 0;

			if (sig[i] == '+') {
				sign.push_back(1);
			}
			else
				sign.push_back(0);
		}
		else {
			num = (num * 10) + (sig[i] - '0');
		}
	}

	nums.push_back(num);

	for (int i{ 0 }; i < sign.size(); i++) {
		if (sign[i] == 1) {
			sum += nums[i];
		}
		else {
			if (n_count == 0)
				answer = sum;
			else {
				answer -= sum;
			}
			n_count++;
			sum = 0;
			sum += nums[i];
		}
	}
	if (sign.size() == 1)
		answer = sum;
	else {
		if (n_count == 0) {
			answer = sum;
		}
		else
		answer -= sum;
	}

	cout << answer << "\n";
}