#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge {
	int u, v, w;
};

int N, M, K;
int parent[1001];
bool power[1001];
vector<Edge> vec;


bool CMP(Edge a, Edge b) {
	return a.w < b.w;
}

int getParent(int u) {
	if (parent[u] == u)
		return u;
	return parent[u] = getParent(parent[u]);
}

void merge(int u, int v) {
	int p1 = getParent(u);
	int p2 = getParent(v);
	if (power[p1] || power[p2]) {
		power[p1] = true;
		power[p2] = true;
	}
	if (p1 > p2)
		parent[p1] = p2;
	else
		parent[p2] = p1;
}

void input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; ++i)
		parent[i] = i;
	for (int i = 0; i < K; ++i) {
		int t;
		cin >> t;
		power[t] = true;
	}
	for (int i = 0; i < M; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		vec.push_back({ u,v,w });
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int answer = 0;
	input();
	sort(vec.begin(), vec.end(), CMP);
	N -= K;
	for (int i = 0; i < vec.size(); ++i) {
		int p1 = getParent(vec[i].u);
		int p2 = getParent(vec[i].v);
		if (power[p1] && power[p2])	continue;
		if (p1 == p2)	continue;
		merge(p1, p2);
		answer += vec[i].w;
		if (--N <= 0)
			break;
	}
	cout << answer;
	return 0;
}