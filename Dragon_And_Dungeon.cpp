// Baekjoon 16434
// Binary Serach

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct Node {
	long long int T, A, H;
}room;
vector<room>dungeon;

long long int N, Hatk, Hmaxhp, T, A, H, r_max;

void p_search(long long int left, long long int right) {
	bool alive;
	long long int mid, answer, atksave, hpsave;
	while (left <= right) {
		alive = true;
		mid = (left + right) / 2;
		hpsave = mid;
		atksave = Hatk;
		for (long long int i{ 0 }; i < N; i++) {
			if (dungeon[i].T == 1) {
				hpsave -= ((dungeon[i].H - 1) / atksave) * dungeon[i].A;
			}
			else if (dungeon[i].T == 2) {
				hpsave += dungeon[i].H;
				atksave += dungeon[i].A;
			}
			if (hpsave <= 0) {
				alive = false;
				break;
			}
			else if (hpsave > mid) {
				hpsave = mid;
			}
		}
		if (alive == false) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
			answer = mid;
		}
	}
	cout << answer << endl;
}

int main() {
	cin >> N >> Hatk;
	for (long long int i{ 0 }; i < N; i++) {
		cin >> T >> A >> H;
		room newroom{ T,A,H };
		dungeon.push_back(newroom);
	}
	p_search(0, 9223372036854775807);
}