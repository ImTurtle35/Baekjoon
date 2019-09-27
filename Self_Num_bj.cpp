// baekjoon 4673
// algorithm study - brute force
#include <iostream>

using namespace std;

bool key;
int save;

int main() {
	for(int i{ 1 }; i <= 10000; i++) {
		key = false;
		for (int j{ i - 37 }; j < i; j++) {
			if (j <= 0) 
				continue;

			else {
				save = j;
				save += j / 10000;
				save += (j % 10000) / 1000;
				save += (j % 1000) / 100;
				save += (j % 100) / 10;
				save += (j % 10);
				if (save == i) {
					key = true;
					break;
				}
			}
		}
		if(key == false)
		cout << i << "\n";
	}
}