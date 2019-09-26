// baekjoon 2985
// algorithm study - brute force
#include <iostream>

using namespace std;

int num1, num2, ans;

void switch_num () {
	int save = num1;
	num1 = num2;
	num2 = ans;
	ans = save;
}

char calcurate(int n) {
	switch (n) {
	case 0:
		if (num1 + num2 == ans)
			return '+';
	case 1:
		if (num1 - num2 == ans)
			return '-';
	case 2:
		if (num1 * num2 == ans)
			return '*';
	case 3:
		if (num1 / num2 == ans)
			return '/';
	default:
		return 'a';
	}
}

int main() {
	cin >> num1 >> num2 >> ans;
	if (calcurate(0) != 'a') {
		cout << num1 << calcurate(0) << num2 << '=' << ans;
		return 0;
	}
	
	switch_num();
	for (int i{ 0 }; i < 4; i++) {
		if (calcurate(i) != 'a') {
			cout << ans << '=' << num1 << calcurate(i) << num2;
			return 0;
		}
	}
}