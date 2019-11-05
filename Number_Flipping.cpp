// Baekjoon 3062
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool yn_key = true;
int T, sum, over;
string N;
vector<int>save;

int main() {
	cin >> T;
	for (int i{ 0 }; i < T; i++) {
		cin >> N;
		save.clear();
		over = 0;
		yn_key = true;
		for (unsigned int j{ 0 }; j < N.length(); j++) {
			sum = (N[j] - '0') + (N[N.length() - 1 - j] - '0') + over;
			over = sum / 10;
			save.push_back(sum % 10);
		}
		if (over > 0) {
			save.push_back(over);
		}
		for (int j{ 0 }; j < (static_cast<int>(save.size()) / 2); j++) {
			if (save[j] != save[save.size() - j - 1]) {
				yn_key = false;
				break;
			}
		}
		if (yn_key == true)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}