// Baekjoon(1753)
// Dijkstra
#include <iostream>
#include <array>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

const int INF = 3000001;
int V, E, K, u, v, w, cur, pre, next_v;
typedef pair<int, int> P;
vector<P>lst[20001];

struct Node{
	int dist = INF;
	bool check = false;
	int path = -1;
};
array<Node, 20001>dp;

void Dijkstra() {
	dp[K].dist = 0;
	priority_queue<P, vector<P>, greater<P>> PQ;
	PQ.push(P(0, K));
	while (!PQ.empty()) {
		int n;
		do {
			n = PQ.top().second;
			PQ.pop();
		} while (!PQ.empty() && dp[n].check);
		// if (PQ.empty()) break;

		dp[n].check = true;

		for (int i{ 0 }; i < lst[n].size(); i++) {
			int nxt = lst[n][i].first;
			int d = lst[n][i].second;
			if (!dp[nxt].check && dp[nxt].dist > dp[n].dist + d) {
				dp[nxt].dist = dp[n].dist + d;
				PQ.push(P(dp[nxt].dist, nxt));
				dp[nxt].path = v;
			}
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> V >> E;
	cin >> K;
	for (int i{ 1 }; i <= E; i++) {
		cin >> u >> v >> w;
		lst[u].push_back({ v, w });
	}
	Dijkstra();
	for (int i{ 1 }; i <= V; i++) {
		if (dp[i].check == false)
			cout << "INF" << endl;
		else
			cout << dp[i].dist << endl;
	}
}