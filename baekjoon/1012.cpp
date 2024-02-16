#include <iostream>
#include <vector>

using namespace std;

bool DFS(int M, int N, int X, int Y, vector<vector<int>>& table, vector<vector<int>>& visited)
{
	if (X < 0 || X >= M || Y < 0 || Y >= N)
		return false;
	if (visited[X][Y] == 1 || table[X][Y] == 0)
		return false;

	visited[X][Y] = 1;

	DFS(M, N, X-1, Y, table, visited);
	DFS(M, N, X+1, Y, table, visited);
	DFS(M, N, X, Y-1, table, visited);
	DFS(M, N, X, Y+1, table, visited);

	return true;
}

int solve(int M, int N, vector<vector<int>>& vec)
{
	int result = 0;
	vector<vector<int>> visited(M, vector<int>(N));
	vector<vector<int>> table(M, vector<int>(N));
	// table √ ±‚»≠
	for (int i = 0; i < vec.size(); ++i)
		table[vec[i][0]][vec[i][1]] = 1;

	for (int i = 0; i < M; ++i)
		for (int j = 0; j < N; ++j)
			if (DFS(M, N, i, j, table, visited))
				++result;
		
	return result;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		vector<vector<int>> V;
		int M, N, K;
		cin >> M >> N >> K;
		for (int j = 0; j < K; ++j)
		{
			int a, b;
			cin >> a >> b;
			V.push_back({ a,b });
		}
		cout << solve(M,N,V) << endl;
	}
	return 0;
}