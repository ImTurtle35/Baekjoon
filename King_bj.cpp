// baekjoon 1063

#include <iostream>
#include <string>

using namespace std;

string king;
string rock;
int N, k0, k1, r0, r1, sk0, sk1, sr0, sr1;
string order;

bool comp() {
	if (sr0 == sk0 && sr1 == sk1)
		return true;
	else
		return false;
}

int main() {
	cin >> king >> rock >> N;
	k0 = king[0] - 'A';
	k1 = king[1] - '1';
	r0 = rock[0] - 'A';
	r1 = rock[1] - '1';
	for (int i{ 0 }; i < N; i++) {
		sk0 = k0;
		sr0 = r0;
		sr1 = r1;
		sk1 = k1;
		cin >> order;
		if (order == "R") {
			sk0++;
			if (comp()) {
				sr0++;
			}
		}
		else if (order == "L") {
			sk0--;
			if (comp()) {
				sr0--;
			}
		}
		else if (order == "B") {
			sk1--;
			if (comp()) {
				sr1--;
			}
		}
		else if (order == "T") {
			sk1++;
			if (comp()) {
				sr1++;
			}
		}
		else if (order == "RT") {
			sk0++; sk1++;
			if (comp()) {
				sr0++; sr1++;
			}
		}
		else if (order == "LT") {
			sk0--; sk1++;
			if (comp()) {
				sr0--; sr1++;
			}
		}
		else if (order == "RB") {
			sk0++; sk1--;
			if (comp()) {
				sr0++; sr1--;
			}
		}
		else{
			sk0--; sk1--;
			if (comp()) {
				sr0--; sr1--;
			}
		}
		if ((0 <= sk0 && sk0 < 8) && (0 <= sk1 && sk1 < 8) && (0 <= sr0 && sr0 < 8) && (0 <= sr1 && sr1 < 8)) {
			k0 = sk0, k1 = sk1, r0 = sr0, r1 = sr1;
		}
	}
	king[0] = k0 + 'A';
	king[1] = k1 + '1';
	rock[0] = r0 + 'A';
	rock[1] = r1 + '1';
	std::cout << king << endl;
	std::cout << rock << endl;
}