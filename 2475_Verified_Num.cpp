// Baekjoon 2475

#include <iostream>

using namespace std;

int input, answer;

int main() {
	for (int i{ 0 }; i < 5; i++) {
		cin >> input;
		answer += input * input;
	}
	cout << answer % 10 << endl;
}