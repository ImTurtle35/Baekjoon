// Baekjoon 1546

#include <iostream>
#include <vector>

using namespace std;

int N,input, max_num;
double answer;
vector<double>grade;

int main() {
	cin >> N;
	for (int i{ 0 }; i < N; i++) {
		cin >> input;
		grade.push_back(input);
		if (input > max_num) max_num = input;
	}
	for (int i{ 0 }; i < N; i++) {
		grade[i] = (grade[i] / max_num) * 100;
		answer += grade[i];
	}
	cout.precision(6);
	cout << answer / N << endl;
}