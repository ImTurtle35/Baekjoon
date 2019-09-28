// baekjoon 2870
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, sum;
vector<string>report;
string save;
string sentence_line;

bool comp(string str1, string str2) {
	if (str1.length() < str2.length()) {
		return true;
	}
	else if (str1.length() == str2.length()) {
		if (str1 < str2)
			return true;
		else
			return false;
	}
	else
		return false;
}

int main() {
	cin >> N;
	for (int i{ 0 }; i < N; i++) {
		cin >> sentence_line;
		save = "";
		for (int j{ 0 }; j < sentence_line.length(); j++) {
			if (sentence_line[j] >= '0' && sentence_line[j] <= '9') {
				if (save == "0") {
					save = "";
				}
				save += sentence_line[j];
			}
			 
			else {
				if (save.length() > 0) {
					report.push_back(save);
					save = "";
				}
			}
		}
		if (save.size() > 0) {
			report.push_back(save);
			save = "";
		}
	}

	sort(report.begin(), report.end(), comp);
	for (int i{ 0 }; i < report.size(); i++) {
		cout << report[i] << endl;
	}
}