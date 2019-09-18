#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

// ������ ��ǥ�� ������ ����ü�� �̸� ������ ���� ����
typedef struct dot_t {
	double X;
	double Y;
} Dot;
vector<Dot> Dots;

// ������ ������ �̿��� �ﰢ���� ���̸� ���ϴ� �Լ� ����
double triangle_area(const Dot d1, const Dot d2, const Dot d3) {
	double ta;
	ta = ((d2.X - d1.X) * (d3.Y - d1.Y) - ((d2.Y - d1.Y) * (d3.X - d1.X))) / 2;
	return ta;
}

int main() {
	int N;
	double result = 0;
	cin >> N;
	Dots.resize(N);

	// ������ ��ǥ�� �Է�
	for (int i{ 0 }; i < N; i++) {
		cin >> Dots[i].X >> Dots[i].Y;
	}

	// � �ٰ����̴��� �ﰢ���� �հ� ���� ��Ÿ�� �� �ִٰ� ����
	// ������ ������ �̿��� �ﰢ���� ���̸� ���ϰ� �̸� ���� �ٰ����� ������ ����
	for (int i{ 0 }; i < N - 2; i++) {
		result += triangle_area(Dots[0], Dots[i + 1], Dots[i + 2]);
	}

	// �Ҽ� ��° �ڸ����� �ݿø��켭 ǥ��, ���̶� ���밪���� ǥ��
	cout << fixed << setprecision(1) << fabs(result) << endl;
}