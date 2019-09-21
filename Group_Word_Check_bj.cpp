// baekjoon 1316
#include <iostream>
#include <string>

using namespace std;

int N, n_count, length;
string word;
bool key;

int main() {
	cin >> N;
	for (int i{ 0 }; i < N; i++) {
		key = true;
		cin >> word;
		length = word.length();
		for (int j{ 0 }; j < length; j++) {
			if (j > 0) {
				if (word[j] != word[j - 1]) {
					for (int k{ 0 }; k < j-1; k++) {
						if (word[k] == word[j]) {
							key = false;
							break;
						}
					}
				}
			}
		}
		if (key == true)
			n_count++;
	}
	cout << n_count << endl;
}