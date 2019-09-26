// baekjoon 2798
// brute force
// algorithm study
#include <iostream>
#include <vector>

using namespace std;

int N, M, card_num ,save, three_card;
vector<int>card;

int main() {
	cin >> N >> M;
	for (int i{ 0 }; i < N; i++) {
		cin >> card_num;
		card.push_back(card_num);
	}

	for (int i{ 0 }; i < N - 2; i++) {
		for (int j{ i + 1 }; j < N - 1; j++) {
			for (int k{ j + 1 }; k < N; k++) {
				three_card = card[i] + card[j] + card[k];
				if (three_card <= M) {
					if (save == 0) {
						save = three_card;
					}
					else if (save < three_card) {
						save = three_card;
					}
				}
			}
		}
	}

	cout << save << "\n";
}