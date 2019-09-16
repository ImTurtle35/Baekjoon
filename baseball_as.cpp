#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef struct team_t {
	string name;
	int win;
	int draw;
	int loss;
	int game;
	int rate;
	int rank;
} Team;

typedef struct class_t {
	Team t[8];
} Class;

int search(string, Class);
bool compare(string, string, Class);
bool cmp(Team, Team);

int main() {
	int T;
	cin >> T;

	for (int h{ 0 }; h < T; h++) {
		bool hope;
		Class C;
		string name, myfavor;
		int win, draw, loss, game, rate, left_game;

		for (int i{ 0 }; i < 8; i++) {
				cin >> C.t[i].name >> C.t[i].win >> C.t[i].draw >> C.t[i].loss;
				C.t[i].game = C.t[i].win + C.t[i].draw + C.t[i].loss;
				C.t[i].rate = C.t[i].win / C.t[i].game;
		}
		
		cin >> myfavor;
		cin >> left_game;
		string lt, rt;
		
		for (int i{ 0 }; i < left_game; i++) {
			cin >> lt >> rt;
			if (lt == myfavor) {
				C.t[search(lt, C)].win += 1;
				C.t[search(rt, C)].loss += 1;
			}
			else if (rt == myfavor) {
				C.t[search(rt, C)].win += 1;
				C.t[search(lt, C)].loss += 1;
			}
			else {
				if (compare(lt, rt, C) == true) {
					C.t[search(lt, C)].win += 1;
					C.t[search(rt, C)].loss += 1;
				}
				else {
					C.t[search(rt, C)].win += 1;
					C.t[search(lt, C)].loss += 1;
				}
			}
		}

		for (int i{ 0 }; i < 8; i++) {
			C.t[i].game = C.t[i].win + C.t[i].draw + C.t[i].loss;
			C.t[i].rate = C.t[i].win / C.t[i].game;
		}

		sort(C.t, C.t + 7, cmp);

		if (C.t[search(myfavor, C)].rate >= C.t[3].rate) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO";
		}
	}
}

int search(string s, Class C) {
	for (int i{ 0 }; i < 8; i++) {
		if (C.t[i].name == s) {
			return i;
		}
	}
}

bool compare(string l, string r, Class C) {
	if (C.t[search(l, C)].rate >= C.t[search(r, C)].rate) {
		return true;
	}
	else
		return false;
}

bool cmp(Team a, Team b) {
	return (a.rate < b.rate);
}