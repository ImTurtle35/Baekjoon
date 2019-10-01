// baekjoon
// greedy
#include <iostream>
#include <algorithm>

using namespace std;

int N, save, n_count;

// ȸ���� ������ �����ϴ� ����ü
typedef struct meeting_time {
	int start;
	int end;
}mtime;

// ����ü �迭 ���������� ���� (���� �Լ������� �޸� �ʰ�)
mtime mt[100000];

// sort�Լ��� ���� ������ ���� �Լ� ����
bool comp(const mtime& t1, const mtime& t2) {
	if (t1.end == t2.end)
		return t1.start < t2.start;

	return t1.end < t2.end;
}

int main() {

	// ȸ���� ������ ����
	cin >> N;
	for (int i{ 0 }; i < N; i++) {
		cin >> mt[i].start >> mt[i].end;
	}

	// ���ǿ� ���� ������ ����
	// ȸ�ǰ� ������ �ð��� ���� ����, ������ �ð��� ������ ���� �ð��� ���� ����
	sort(mt, mt+N, comp);

	// �ִ��� �̾Ƴ� �� �ִ� ȸ�� �ð� ����
	for (int i{ 0 }; i < N; i++) {
		if (i == 0) {
			save = i;
			n_count++;
		}
		else {
			if (mt[save].end <= mt[i].start) {
				save = i;
				n_count++;
			}
		}
	}

	cout << n_count << "\n";
}