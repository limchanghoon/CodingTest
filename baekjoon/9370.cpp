#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct CMP {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int n, m, t, s, g, h;
		cin >> n >> m >> t >> s >> g >> h;
		vector<vector<pair<int,int>>> edge(n + 1);
		vector<int> des;
		for (int i = 0; i < m; ++i) {
			int a, b, d;
			cin >> a >> b >> d;
			edge[a].push_back({ b,d });
			edge[b].push_back({ a,d });
		}
		for (int i = 0; i < t; ++i) {
			int x;
			cin >> x;
			des.push_back(x);
		}
		sort(des.begin(), des.end());

		// �߰� ���� ã�� (s => mid)
		vector<int> dist(n + 1, 2000000000);
		priority_queue<pair<int, int>, vector<pair<int, int>>, CMP> pq;
		dist[s] = 0;
		pq.push({ s,0 });
		while (!pq.empty()) {
			int cur = pq.top().first;
			int cost = pq.top().second;
			pq.pop();

			if (dist[cur] < cost) continue;

			for (int i = 0; i < edge[cur].size(); ++i) {
				int next = edge[cur][i].first;
				int nextCost = cost + edge[cur][i].second;
				if (dist[next] <= nextCost) continue;
				dist[next] = nextCost;
				pq.push({ next, nextCost });
			}
		}
		int mid = dist[g] > dist[h] ? g : h;

		// (mid => ������)
		vector<int> dist_mid(n + 1, 2000000000);
		dist_mid[mid] = 0;
		pq.push({ mid,0 });
		while (!pq.empty()) {
			int cur = pq.top().first;
			int cost = pq.top().second;
			pq.pop();

			if (dist_mid[cur] < cost) continue;

			for (int i = 0; i < edge[cur].size(); ++i) {
				int next = edge[cur][i].first;
				int nextCost = cost + edge[cur][i].second;
				if (dist_mid[next] <= nextCost) continue;
				dist_mid[next] = nextCost;
				pq.push({ next, nextCost });
			}
		}

		// (s=>mid=>������) == (s=>������) ã��
		for (int i = 0; i < des.size(); ++i) {
			int D = des[i];
			if (dist[mid] + dist_mid[D] != dist[D]) continue;
			cout << D << " ";
		}
		cout << "\n";
	}
	return 0;
}