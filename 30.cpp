// Baekjoon 10610
// Greedy Algorithm

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
string N;
int save;
bool zero;
bool three;

bool temp(char a, char b) {
	if (a > b)
		return true;
	else
		return false;
}

int main() {
	cin >> N;
	sort(N.begin(), N.end(), temp);
	for (size_t i{ 0 }; i < N.length(); i++) {

		if (N[i] == '0') {
			if (i == 0) {
				cout << "-1";
				return 0;
			}
			zero = true;
			break;
		}
		else {
			save += (N[i] - '0');
			save %= 3;
		}
	}
	
	if (save == 0)
		three = true;
	if (zero == false || three == false) {
		cout << "-1";
		return 0;
	}
	else {
		cout << N;
	}
}