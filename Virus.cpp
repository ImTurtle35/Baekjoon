// Baekjoon (2606)
// Stack

#include <iostream>
#include <stack>

using namespace std;

bool key;
int computer, net, network1, network2, answer;
int c_net[101][101];
int check[101];
stack<int>virus;

int main() {
	cin >> computer;
	cin >> net;
	for (int i{ 0 }; i < net; i++) {
		cin >> network1 >> network2;
		c_net[network1][network2] = 1;
		c_net[network2][network1] = 1;
	}
	virus.push(1);
	check[1] = 1;
	while (virus.empty() != true) {
		key = true;
		for (int i{ 1 }; i <= computer; i++) {
			if (c_net[virus.top()][i] == 1 && check[i] != 1) {
				virus.push(i);
				check[i] = 1;
				answer++;
				key = false;
				break;
			}
		}
		if (key == true) {
			for (int i{ 1 }; i <= computer; i++) {
				if (c_net[virus.top()][i] == 1 && check[i] == 1) {
					virus.pop();
					break;
				}
			}
		}
	}
	cout << answer << endl;
}