#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct Edge{
	int des, cost;
	Edge(int _des, int _cost)
	{
		des = _des;
		cost = _cost;
	}
};

struct cmp
{
	bool operator()(const Edge& a, const Edge& b)
	{
		return a.cost > b.cost;
	}
};

vector<int> costs;
vector<vector<Edge>> edges;
vector<int> dp;

void dijkstra(int s)
{
	priority_queue<Edge,vector<Edge>,cmp> pq;

	pq.push(Edge(s, 0));
	costs[s] = 0;
	while (!pq.empty())
	{
		int cur = pq.top().des;
		int cost = pq.top().cost;
		pq.pop();

		if (cost > costs[cur]) continue;
		
		for (int i = 0; i < edges[cur].size(); ++i)
		{
			int next = edges[cur][i].des;
			int nextCost = edges[cur][i].cost + cost;

			if (nextCost < costs[next])
			{
				costs[next] = nextCost;
				pq.push(Edge(next, nextCost));
			}

			if (costs[cur] > costs[next]) {
				dp[cur] += dp[next];
			}
		}
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	costs.resize(N + 1, INT32_MAX);
	edges.resize(N + 1);
	dp.resize(N + 1);
	dp[2] = 1;
	for (int i = 0; i < M; ++i) {
		int A, B, C;
		cin >> A >> B >> C;
		edges[A].push_back(Edge(B, C));
		edges[B].push_back(Edge(A, C));
	}

	dijkstra(2);

	cout << dp[1] << endl;
}