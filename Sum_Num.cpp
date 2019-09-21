#include <iostream>
#include <string>

using namespace std;

int N, result;
string S;

int main() {
	cin >> N;
	cin >> S;
	for (int i{ 0 }; i < N; i++) {
		result += S[i] - 48;
	}
	cout << result;
}