#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// �� ���� ������ �����ϱ� ���� ����ü ����
typedef struct team_t {
	string name;
	int win;
	int draw;
	int loss;
    int game;
	int rate;
} Team;

// ������ ���� ����ü ����
typedef struct class_t {
	Team t[8];
} Class;

// Ư�� ���� ã�� �Լ�
int search(string, Class);

// ���� �Լ� ����
int main() {
	int T;
	cin >> T;

	for (int h{ 0 }; h < T; h++) {
		Class C;
		string name, myfavor, lt, rt;
		int left_game;

		// �� ���� ������ �Է�
		for (int i{ 0 }; i < 8; i++) {
				cin >> C.t[i].name >> C.t[i].win >> C.t[i].draw >> C.t[i].loss;
		}
		
		cin >> myfavor;
		cin >> left_game;
		
		// ���� ���� ������ ���� ��ȣ�ϴ� ���� �÷��̿����� ������ ���� ���� ���ɼ��� ����
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

		// �� ���� �������� ���� �·��� ���
		for (int i{ 0 }; i < 8; i++) {
			C.t[i].game = C.t[i].win + C.t[i].draw + C.t[i].loss;
			if (C.t[i].game != 0)
				C.t[i].rate = (C.t[i].win * 10000) / C.t[i].game;
			else
				C.t[i].rate = 0;
		}

		int save_rate = C.t[search(myfavor, C)].rate;
		int count = 0;

		// �����ϴ� ������ �·��� ���� ���� �� �� �����̸� �÷��̿����� ���� ���ɼ��� �����Ƿ� �̿� ���� �з�
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