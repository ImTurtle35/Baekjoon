// baekjoon - 1874
#include <iostream>
#include <vector>

using namespace std;

bool pos;
int n, num, n_count, len;
vector<int>n_arr;
vector<int>stack;
vector<char>pupo;

int main() {
	pos = true;
	cin >> n;
	for (int i{ 1 }; i < n+1; i++) {
		cin >> num;
		n_arr.push_back(num);
	}
	for (int i{ 1 }; i < n + 1; i++) {
		stack.push_back(i);
		pupo.push_back('+');
		if (n_arr[n_count] == i) {
			stack.pop_back();
			pupo.push_back('-');
			n_count++;
			if (n_count != n && stack.size() != 0) {
				for (int j{ i - 1 }; j > 0; j--) {
					if (n_arr[n_count] == j) {
						stack.pop_back();
						pupo.push_back('-');
						n_count++;
					}
				}
			}
		}
	}
	len = stack.size();
	for (int i{ 0 }; i < len; i++) {
		if (n_arr[n_count] == stack[len-1]) {
			stack.pop_back();
			pupo.push_back('-');
			n_count++;
			pos = true;
		}
		else {
			pos = false;
		}
	}

	if (pos == false) {
		cout << "NO\n";
	}
	else {
		for(int i{0}; i < pupo.size() ; i++) {
			cout << pupo[i] << "\n";
		}
	}
}