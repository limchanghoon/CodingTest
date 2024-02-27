#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int parent[1001];
bool man[1001];

struct E {
	int x, y, cost;
};

struct CMP {
	bool operator()(E a, E b) {
		return a.cost > b.cost;
	}
};

int getParent(int a) {
	if (parent[a] == a)	return a;
	return parent[a] = getParent(parent[a]);
}

void merge(int a, int b) {
	int pa = getParent(a);
	int pb = getParent(b);

	if (pa < pb)	parent[pb] = parent[pa];
	else	parent[pa] = parent[pb];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int answer = 0;
	priority_queue<E, vector<E>, CMP> pq;

	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		char c;
		cin >> c;
		if (c == 'M')
			man[i] = true;
		parent[i] = i;
	}

	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		if (man[a] == man[b])
			continue;
		pq.push({ a,b,c });
	}

	while (!pq.empty()) {
		auto cur = pq.top();
		pq.pop();
		if (getParent(cur.x) == getParent(cur.y))	continue;
		merge(cur.x, cur.y);
		answer += cur.cost;
		if (--N == 1)
			break;
	}

	if (N > 1)cout << -1;
	else	cout << answer;

	return 0;
}