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
	saving_str = ""; // �ʼ�
	answer = ""; // �ʼ�
	result.clear(); // �ʼ�
	ch1 = 0; 
	ch2 = 0;
	save = 0; // �ʼ�
	cal = 0;
	len = str.length();
	len2 = str2.length();
	// str�� str2���� ���̰� ������ ũ�ų� ����.
	// ��� �ϱ����� str ���̸� 0�� �־� ���߱�.
	for (int i{ 0 }; i < len - len2; i++) {
		saving_str += "0";
	}
	saving_str += str2;
	// ���Ŀ� ����־� result�� ����ֱ�
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
	// result�� answer�� �����鼭 ���� �������
	for (size_t i{ 0 }; i < result.size(); i++) {
		answer += result[(result.size()) - 1 - i];
	}
	return answer;
}

// dp�� Ȱ���� ��� ����
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