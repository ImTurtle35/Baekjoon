// Baekjoon 1654
// Bineary Search

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long int K, N, lan, max_lan, save, answer;
vector<long long int>lans;

void P_Search(long long int left,long long int right, long long int mid) {
	while (left <= right) {
		mid = (left + right) / 2;
		save = 0;
		for (long long int i{ 0 }; i < K; i++) {
			save += lans[i] / mid;
		}
		if (save < N) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
			if (answer < mid) {
				answer = mid;
			}
		}	
	}
	cout << answer << endl;
}

int main() {
	cin >> K >> N;
	for (long long int i{ 0 }; i < K; i++) {
		cin >> lan;
		lans.push_back(lan);
	}
	sort(lans.begin(), lans.end());
	max_lan = lans[K-1];
	P_Search(1, max_lan, (1 + max_lan) / 2);
}