#include <iostream>

using namespace std;

int factorial(int N) {
	if (N == 0 || N ==1) {
		return 1;
	}
	else {
		return N * factorial(N-1);
	}
}

int main() {
	int N;
	int i = 0;
	cin >> N;
	cout << factorial(N);

}