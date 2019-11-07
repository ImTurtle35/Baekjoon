// Baekjoon(2667)
// Stack

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

bool key;
int N, home_count, point;
string line;
int village[625];
int check[625];
stack<int>save;
vector<int>answer;

int main() {
	cin >> N;
	for (int i{ 0 }; i < N; i++) {
		cin >> line;
		for (int j{ 0 }; j < N; j++) {
			if (line[j] == '1') {
				village[i * N + j] = 1;
			}
		}
	}
	for (int i{ 0 }; i < N; i++) {
		for (int j{ 0 }; j < N; j++) {
			if (village[i * N + j] == 1 && check[i * N + j] != 1) {
				home_count = 1;
				save.push(i * N + j);
				check[i * N + j] = 1;
				while (save.empty() == false) {
					key = true;
					point = save.top();
					if ((point % N > 0) && (village[point - 1] == 1) && check[point - 1] != 1) {
						save.push(point - 1);
						check[point - 1] = 1;
						home_count++;
						key = false;
					}
					else if (point % N < N - 1 && village[point + 1] == 1 && check[point + 1] != 1) {
						save.push(point + 1);
						check[point + 1] = 1;
						home_count++;
						key = false;
					}
					else if (point / N > 0 && village[point - N] == 1 && check[point - N] != 1) {
						save.push(point - N);
						check[point - N] = 1;
						home_count++;
						key = false;
					}
					else if (point / N < N - 1 && village[point + N] == 1 && check[point + N] != 1) {
						save.push(point + N);
						check[point + N] = 1;
						home_count++;
						key = false;
					}

					if (key == true) {
						save.pop();
					}
				}

				answer.push_back(home_count);
			}
		}
	}
	sort(answer.begin(), answer.end());
	cout << answer.size() << endl;
	for (int i{ 0 }; i < answer.size(); i++) {
		cout << answer[i] << endl;
	}
}