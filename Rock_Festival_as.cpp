// Algospot FESTIVAL
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

double testcase, p_date, must, average, min_num, save, n_count;
int expense[1001];

int main() {
	cin >> testcase;
	for (int i = 0; i < testcase; i++) {
		min_num = 0;
		cin >> p_date >> must;

		for (int j = 0; j < p_date; j++) {
			cin >> expense[j];
		}

		for (int j = 0; j < p_date + 1 - must; j++) {
			save = 0;
			n_count = 0;
			for (int k = j; k < p_date; k++) {
				save += expense[k];
				n_count++;
				if (n_count >= must) {
					if (min_num == 0 || min_num > save / n_count)
						min_num = save / n_count;
				}
			}
		}

		cout << fixed << setprecision(15) << min_num << endl;
	}
}