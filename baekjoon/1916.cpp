#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cmp {
	bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
	}
};


int main()
{
	int N, M, S, E;
	cin >> N >> M;

	vector<vector<pair<int,int>>> edges(N + 1);

	for (int i = 0; i < M; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;

		edges[a].push_back({ b,c });
	}
	cin >> S >> E;


	vector<int> costs(N + 1, INT32_MAX/2);

	priority_queue<pair<int,int>, vector<pair<int, int>>, cmp> pq;
	pq.push({ S,0 });
	while (!pq.empty())
	{
		int cur = pq.top().first;
		int cost = pq.top().second;
		pq.pop();

		if (cost >= costs[cur])	continue;

		costs[cur] = cost;

		for (int i = 0; i < edges[cur].size(); ++i)
		{
			int next = edges[cur][i].first;
			int nextCost = edges[cur][i].second;

			if (cost + nextCost < costs[next])
				pq.push({ next, cost + nextCost });
		}
	}

	cout << costs[E] << endl;

	return 0;
}