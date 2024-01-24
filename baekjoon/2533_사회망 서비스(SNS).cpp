#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

int answer = 0;
vector<vector<int>> edges;
vector<int> visited;
deque<bool> earlyAdapter;

void DFS(int n)
{
	visited[n] = true;
	for (int i = 0; i < edges[n].size(); ++i)
	{
		int child = edges[n][i];
		if (!visited[child])
			DFS(child);
	}
	if (!earlyAdapter[n])
	{
		for (int i = 0; i < edges[n].size(); ++i)
		{
			int parent = edges[n][i];
			if (!earlyAdapter[parent])
			{
				++answer;
				earlyAdapter[parent] = true;
				break;
			}
		}
	}
}

int main()
{
	int N;
	int K, M, P;
	cin >> N;
	edges.resize(N + 1);
	visited.resize(N + 1);
	earlyAdapter.resize(N + 1);
	for (int i = 0; i < N - 1; ++i)
	{
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	DFS(1);

	cout << answer << endl;


	return 0;
}