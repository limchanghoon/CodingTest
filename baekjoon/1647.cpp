#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
	int FROM, TO, COST;
};

int parent[100001];

int getParent(int x) {
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent[x]);
}

void merge(int x, int y) {
	int px = getParent(x);
	int py = getParent(y);

	if (px > py) parent[px] = py;
	else parent[py] = px;
}

bool cmp(const Edge& a, const Edge& b) {
	return a.COST < b.COST;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int ans = 0, count = 0;
	int N, M;
	cin >> N >> M;
	vector<Edge> table(M);
	for (int i = 1; i <= N; ++i) parent[i] = i;
	for (int i = 0; i < M; ++i) {
		cin >> table[i].FROM >> table[i].TO >> table[i].COST;
	}
	sort(table.begin(), table.end(), cmp);

	for (int i = 0; i < M; ++i) {
		if (count == N - 2)break;
		if (getParent(table[i].FROM) == getParent(table[i].TO)) continue;
		merge(table[i].FROM, table[i].TO);
		ans += table[i].COST;
		++count;
	}
	cout << ans;
	return 0;
}