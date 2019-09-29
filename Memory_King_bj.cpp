// baekjoon 2776
// bineary_search
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N, M, save;
vector<int>Note_1;
vector<int>Note_2;

int main(){
	cin >> T;
	for (int i{ 0 }; i < T; i++) {
		Note_1.clear();
		Note_2.clear();
		cin >> N;
		for (int j{ 0 }; j < N; j++) {
			cin >> save;
			Note_1.push_back(save);
		}
		cin >> M;
		for (int j{ 0 }; j < M; j++) {
			cin >> save;
			Note_2.push_back(save);
		}
		sort(Note_1.begin(), Note_1.end());
		for (int j{ 0 }; j < M; j++) {
			cout << binary_search(Note_1.begin(), Note_1.end(), Note_2[j]) << "\n";
		}
	}
}