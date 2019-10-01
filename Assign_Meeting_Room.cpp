// baekjoon
// greedy
#include <iostream>
#include <algorithm>

using namespace std;

int N, save, n_count;

// 회의의 정보를 저장하는 구조체
typedef struct meeting_time {
	int start;
	int end;
}mtime;

// 구조체 배열 전역변수로 생성 (메인 함수에서는 메모리 초과)
mtime mt[100000];

// sort함수에 넣을 정렬의 조건 함수 생성
bool comp(const mtime& t1, const mtime& t2) {
	if (t1.end == t2.end)
		return t1.start < t2.start;

	return t1.end < t2.end;
}

int main() {

	// 회의의 정보를 저장
	cin >> N;
	for (int i{ 0 }; i < N; i++) {
		cin >> mt[i].start >> mt[i].end;
	}

	// 조건에 따라 정보를 정렬
	// 회의가 끝나는 시간에 따라 정렬, 끝나는 시간이 같으면 시작 시간에 따라 정렬
	sort(mt, mt+N, comp);

	// 최대한 뽑아낼 수 있는 회의 시간 세기
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