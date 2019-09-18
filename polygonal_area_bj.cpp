#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

// 점들의 좌표를 저장할 구조체와 이를 모으는 벡터 생성
typedef struct dot_t {
	double X;
	double Y;
} Dot;
vector<Dot> Dots;

// 벡터의 외적을 이용해 삼각형의 넓이를 구하는 함수 생성
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

	// 점들의 좌표를 입력
	for (int i{ 0 }; i < N; i++) {
		cin >> Dots[i].X >> Dots[i].Y;
	}

	// 어떤 다각형이던지 삼각형의 합과 차로 나타낼 수 있다고 생각
	// 벡터의 외적을 이요해 삼각형의 넓이를 구하고 이를 더해 다각형의 면적을 산출
	for (int i{ 0 }; i < N - 2; i++) {
		result += triangle_area(Dots[0], Dots[i + 1], Dots[i + 2]);
	}

	// 소수 둘째 자리에서 반올림헤서 표기, 넓이라서 절대값으로 표기
	cout << fixed << setprecision(1) << fabs(result) << endl;
}