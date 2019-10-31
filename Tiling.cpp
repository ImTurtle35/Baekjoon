// Baekjoon 1793
// Dynamic Programming

#include <iostream>
#include <vector>

using namespace std;

string arr[252];
string saving_str = "";
string answer = "";
vector<char>result;
int ch1;
int ch2;
int save;
int cal;
int len;
int len2;

string calculate (const string & str, const string & str2) {
	saving_str = ""; // 필수
	answer = ""; // 필수
	result.clear(); // 필수
	ch1 = 0; 
	ch2 = 0;
	save = 0; // 필수
	cal = 0;
	len = str.length();
	len2 = str2.length();
	// str이 str2보다 길이가 무조건 크거나 같다.
	// 계산 하기전에 str 길이를 0을 넣어 맞추기.
	for (int i{ 0 }; i < len - len2; i++) {
		saving_str += "0";
	}
	saving_str += str2;
	// 공식에 집어넣어 result에 집어넣기
	for (int i{ len - 1 }; i >= 0; i--) {
		ch1 = str[i] - '0';
		ch2 = saving_str[i] - '0';
		cal = ch1 + (ch2 * 2) + save;
		result.push_back((cal%10) + '0');
		save = cal / 10;
		if (i == 0 && save > 0) {
			result.push_back(save + '0');
		}
	}
	// result를 answer에 넣으면서 순서 원래대로
	for (size_t i{ 0 }; i < result.size(); i++) {
		answer += result[(result.size()) - 1 - i];
	}
	return answer;
}

// dp를 활용해 결과 산출
string rec(int n) {
	if (arr[n] != "") return arr[n];
	if (n == 1) return "1";
	else if (n == 2) return "3";
	else if (n == 3) return "5";
	else if (n == 4) return "11";
	else {
		arr[n] = calculate(rec(n-1), rec(n-2));
		return arr[n];
	}
}

int main() {
	int n;
	while (cin >> n) {
		if (n == 0)
			cout << "1\n";
		else
		cout << rec(n) << endl;
	}
}