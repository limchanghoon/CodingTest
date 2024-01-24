#include <iostream>
#include <vector>

using namespace std;

bool DFS(int C, vector<vector<int>>& table, vector<int>& visited)
{
	if (visited[C] == 1)
		return false;

	visited[C] = 1;

	for (int i = 0; i < table[C].size(); ++i)
		DFS(table[C][i], table, visited);

	return true;
}


int main()
{
	int result = 0;
	int N, M;
	cin >> N >> M;

	vector<vector<int>> table(N + 1, vector<int>(N + 1));
	vector<int> visited(N + 1);
	for (int i = 0; i < M; ++i)
	{
		int a,b;
		cin >> a >> b;
		table[a].push_back(b);
		table[b].push_back(a);
	}

	for (int i = 1; i <= N; ++i)
		if (DFS(i, table, visited))
			++result;

	cout << result << endl;

	return 0;
}