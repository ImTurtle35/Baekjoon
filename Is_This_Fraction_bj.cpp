// baekjoon 2863
// algorithm study - brute force
#include <iostream>

using namespace std;

int r_count;
double sum_max;
double pyo[2][2];

double calcurate(double pyo[2][2]) {
	return (pyo[0][0] / pyo[1][0]) + (pyo[0][1] / pyo[1][1]);
}

void rotate(double pyo[2][2]) {
	double save = 0;
	save = pyo[0][0];
	pyo[0][0] = pyo[1][0];
	pyo[1][0] = pyo[1][1];
	pyo[1][1] = pyo[0][1];
	pyo[0][1] = save;
}

int main() {
	for (int i{ 0 }; i < 2; i++) {
		cin >> pyo[i][0] >> pyo[i][1];
	}

	sum_max = calcurate(pyo);

	for (int i{ 0 }; i < 3; i++) {
		rotate(pyo);
		if (sum_max < calcurate(pyo)) {
			sum_max = calcurate(pyo);
			r_count = i + 1;
		}
	}

	cout << r_count << "\n";
}