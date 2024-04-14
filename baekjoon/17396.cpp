#include <iostream>
#include <queue>
#include <vector>
#include <limits>

using namespace std;

int N, M;

struct EdgeStruct {
	int des;
	long long cost;
};

struct CMP {
	bool operator()(const EdgeStruct& a, const EdgeStruct& b) {
		return a.cost > b.cost;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	vector<int> visible(N);
	vector<long long> dist(N, numeric_limits<long long>::max());
	vector<vector<EdgeStruct>> edge(N);
	for (int i = 0; i < N; ++i) {
		cin >> visible[i];
	}
	visible[N - 1] = 0;
	for (int i = 0; i < M; ++i) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		if (visible[a] == 1 || visible[b] == 1) continue;
		edge[a].push_back({ b,c });
		edge[b].push_back({ a,c });
	}

	priority_queue<EdgeStruct, vector<EdgeStruct>, CMP> pq;
	dist[0] = 0;
	pq.push({ 0,0 });

	while (!pq.empty()) {
		long long des = pq.top().des;
		long long cost = pq.top().cost;
		pq.pop();

		if (dist[des] < cost) continue;
		dist[des] = cost;

		if (des == N - 1) {
			cout << cost;
			return 0;
		}

		for (int i = 0; i < edge[des].size(); ++i) {
			int nextDes = edge[des][i].des;
			long long nextCost = edge[des][i].cost + cost;
			if (dist[nextDes] <= nextCost) continue;
			dist[nextDes] = nextCost;
			pq.push({ nextDes, nextCost });
		}
	}
	cout << -1;
	return 0;
}