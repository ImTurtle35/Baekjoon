#include <iostream>
#include <vector>

using namespace std;

typedef struct num_t {
	int num;
	bool lower = false;
} Nt;
vector<Nt>numbers;
int N, X;

int main() {
	int N, X;
	cin >> N >> X;
	numbers.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> numbers[i].num;
		if (numbers[i].num < X)
			numbers[i].lower = true;
	}
	for (int i = 0; i < N; i++) {
		if (numbers[i].lower == true)
			cout << numbers[i].num << " ";
	}
}