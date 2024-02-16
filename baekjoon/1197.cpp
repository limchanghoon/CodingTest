#include <iostream>
#include <vector>
#include <deque>
#include <queue>
using namespace std;

struct cmp{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		return a.second > b.second;
	}
};

int main()
{
	int answer = 0;
	int V, E;
	cin >> V >> E;
	vector<vector<pair<int,int>>> edges(V + 1);
	deque<bool> checks(V + 1);
	for (int i = 0; i < E; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({ b,c });
		edges[b].push_back({ a,c });
	}

	priority_queue<pair<int,int>, vector<pair<int, int>>, cmp> pq;

	checks[1] = true;
	for (int i = 0; i < edges[1].size(); ++i)
	{
		pq.push({ edges[1][i].first, edges[1][i].second });
	}

	while (!pq.empty())
	{
		int next = pq.top().first;
		int cost = pq.top().second;

		pq.pop();

		if (checks[next] == true)
			continue;

		answer += cost;
		checks[next] = true;
		for (int i = 0; i < edges[next].size(); ++i)
		{
			pq.push({ edges[next][i].first, edges[next][i].second });
		}
	}

	cout << answer << endl;

	return 0;
}