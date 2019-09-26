// baekjoon 10809
// algorithm study - brute force
#include <iostream>
#include <string>

using namespace std;

string word;
int alphabet[26];

int main() {
	for (int i{ 0 }; i < 26; i++) {
		alphabet[i] = -1;
	}
	cin >> word;
	for(int i{ 0 }; i < word.length(); i++) {
		if (alphabet[word[i] - 'a'] == -1) {
			alphabet[word[i] - 'a'] = i;
		}
	}
	for (int i{ 0 }; i < 26; i++) {
		cout << alphabet[i] << " ";
	}
}