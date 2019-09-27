// baekjoon 7568
// algorithm study - brute force
#include <iostream>
#include <vector>

using namespace std;

int N,W,H,win_count;

typedef struct person_t {
	int weight;
	int height;
	int rate;
} person;
vector<person>group;

int main() {
	cin >> N;
	for (int i{ 0 }; i < N; i++) {
		cin >> W >> H;
		person* newperson = (person*)malloc(sizeof(person));
		newperson->weight = W;
		newperson->height = H;
		group.push_back(*newperson);
	}
	for (int i{ 0 }; i < N; i++) {
		win_count = 1;
		for (int j{ 0 }; j < N; j++) {
			if (i == j)
				continue;
			else {
				if (group[j].height > group[i].height && group[j].weight > group[i].weight) {
					win_count++;
				}
			}
		}
		group[i].rate = win_count;
	}
	for (int i{ 0 }; i < N; i++) {
		cout << group[i].rate << " ";
	}
}