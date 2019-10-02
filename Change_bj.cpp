// baekjoon 5585
// greedy algorithm
#include <iostream>

using namespace std;

int taro, ans;

int main() {
	cin >> taro;
	taro = 1000 - taro;
	ans += taro / 500;
	taro %= 500;
	ans += taro / 100;
	taro %= 100;
	ans += taro / 50;
	taro %= 50;
	ans += taro / 10;
	taro %= 10;
	ans += taro / 5;
	taro %= 5;
	ans += taro;
	cout << ans;
}