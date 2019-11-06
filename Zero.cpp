// Baekjoon 10773
// Stack

#include <iostream>
#include <stack>

using namespace std;

int K, number, answer;
stack<int>save;

int main() {
	cin >> K;
	for (int i{ 0 }; i < K; i++) {
		cin >> number;
		if (number != 0) {
			save.push(number);
		}
		else {
			save.pop();
		}
	}
	while (save.empty() == false) {
		answer += save.top();
		save.pop();
	}
	cout << answer << endl;
}