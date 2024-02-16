#include <iostream>
#include <vector>

using namespace std;

int DFS(int P, int result, vector<int>& table, vector<int>& visited)
{
	if (visited[P] == 1)
		return -1;

	visited[P] = 1;
	if(table[P] != 0)
		result = DFS(table[P], result + 1, table, visited);

	return result;
}

int main()
{
	
	int N, M, P;
	cin >> N >> M >> P;

	vector<int> visited(M + 1); // 채널 M가지
	vector<int> table(M + 1); // 채널 M가지
	for (int i = 0; i < N; ++i)
	{
		int f,h;
		cin >> f >> h;
		if (table[h] == 0)
			table[h] = f;
	}

	cout << DFS(P, 0, table, visited) << endl;

	return 0;
}