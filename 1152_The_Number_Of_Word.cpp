// Bakejoon 1152

#include <iostream>
#include <string>

using namespace std;

int answer;
bool start;
string input;

int main() {
	getline(cin, input);
	start = false;
	for (int i{ 0 }; i < input.length(); i++) {
		if (start == true && input[i] == ' ') {
			start = false;
		}
		else if (start == false && input[i] != ' ') {
			start = true;
			answer++;
		}
	}
	cout << answer << endl;
}