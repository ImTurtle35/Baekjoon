#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int C, pass;
double N, grade, sum, average , answer;
vector<int>student;

int main() {
	cin >> C;
	for (int i = 0; i < C; i++) {
		pass = 0;
		student.clear();
		sum = 0;
		cin >> N;
		for (int j = 0; j < N; j++) {
			cin >> grade;
			student.push_back(grade);
			sum += grade;
		}
		average = sum / N;
		for (int j = 0; j < N; j++) {
			if(student[j] > average)
				pass++;
		}
		answer = (pass * 100 / N);
		cout << fixed << setprecision(3) << answer << "%\n";
	};
}