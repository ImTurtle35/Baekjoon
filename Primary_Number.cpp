// Baekjoon 2193
// Dynamic Programing
#include <iostream>

using namespace std;

long long prinary_number_count(long);

int main() {
	int N;
	cin >> N;
	if (N == 1)
		cout << "1";
	else {
		cout << prinary_number_count(N) << endl;
	}
}

long long prinary_number_count(long num) {
	long long result = 1;
	long long answer = 2;
	long long mid_num = 1;
	long long a = 1;
	if (num == 1)
		return 1;
	else if (num == 2)
		return 1;
	else {
		for (int i{ 0 }; i < num - 2; i++) {
			result += mid_num;
			mid_num = a;
			a = result;

		}
	}
	return result;
}