#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	vector<int> answer;
	int N, M;
	cin >> N >> M;

	vector<vector<int>> edges(N+1);
	vector<int> into(N + 1);
	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		++into[b];
	}

	queue<int> q;
	for (int i = 1; i <= N; ++i)
	{
		if (into[i] == 0)
		{
			q.push(i);
		}
	}
	while(!q.empty())
	{
		int cur = q.front();
		q.pop();
		answer.push_back(cur);
		for (int j = 0; j < edges[cur].size(); ++j)
		{
			if (--into[edges[cur][j]] == 0)
				q.push(edges[cur][j]);
		}
	}

	for (int i = 0; i < answer.size(); ++i)
	{
		cout << answer[i] << " ";
	}
	

	return 0;
}