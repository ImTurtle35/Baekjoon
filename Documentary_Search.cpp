// Baekjoon 1543
// Greedy Algorithm

#include <iostream>
#include <string>

using namespace std;

string doc;
string object;
char save;
bool comp;
int answer;
unsigned int d_len;
unsigned int o_len;

int main() {
	getline(cin, doc);
	d_len = doc.length();
	getline(cin, object);
	o_len = object.length();
	save = object[0];
	if (d_len < o_len) {
		cout << "0\n";
		return 0;
	}
	for (int i{ 0 }; i < d_len - o_len + 1; i++) {
		if (doc[i] == save) {
			comp = true;
			for (int j{ 1 }; j < o_len; j++) {
				if (doc[i + j] != object[j]) {
					comp = false;
					break;
				}
				else {
					comp = true;
				}
			}
			if (comp == true) {
				i += (o_len - 1);
				answer++;
			}
		}
	}
	cout << answer;
}