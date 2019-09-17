#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// 각 팀의 정보를 저장하기 위한 구조체 생성
typedef struct team_t {
	string name;
	int win;
	int draw;
	int loss;
    int game;
	int rate;
} Team;

// 팀들을 묶는 구조체 생성
typedef struct class_t {
	Team t[8];
} Class;

// 특정 팀을 찾는 함수
int search(string, Class);

// 메인 함수 시작
int main() {
	int T;
	cin >> T;

	for (int h{ 0 }; h < T; h++) {
		Class C;
		string name, myfavor, lt, rt;
		int left_game;

		// 각 팀의 성적을 입력
		for (int i{ 0 }; i < 8; i++) {
				cin >> C.t[i].name >> C.t[i].win >> C.t[i].draw >> C.t[i].loss;
		}
		
		cin >> myfavor;
		cin >> left_game;
		
		// 남은 게임 정보를 토대로 선호하는 팀이 플레이오프에 진출할 가장 좋은 가능성을 도출
		for (int i{ 0 }; i < left_game; i++) {
			cin >> lt >> rt;
			if (lt == myfavor) {
				C.t[search(lt, C)].win ++;
				C.t[search(rt, C)].loss ++;
			}
			else if (rt == myfavor) {
				C.t[search(rt, C)].win ++;
				C.t[search(lt, C)].loss ++;
			}
			else {
				C.t[search(lt, C)].draw ++;
				C.t[search(rt, C)].draw ++;
				
			}
		}

		// 각 팀의 성적들을 토대로 승률을 계산
		for (int i{ 0 }; i < 8; i++) {
			C.t[i].game = C.t[i].win + C.t[i].draw + C.t[i].loss;
			if (C.t[i].game != 0)
				C.t[i].rate = (C.t[i].win * 10000) / C.t[i].game;
			else
				C.t[i].rate = 0;
		}

		int save_rate = C.t[search(myfavor, C)].rate;
		int count = 0;

		// 좋아하는 팀보다 승률이 높은 팀이 세 팀 이하이면 플레이오프에 진출 가능성이 있으므로 이에 따라 분류
		for (int i{ 0 }; i < 8; i++) {
			if (save_rate < C.t[i].rate) {
				count++;
			}
		}

		if (count <= 3) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
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