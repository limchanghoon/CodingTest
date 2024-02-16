#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void DFS(vector<vector<int>>& table, deque<bool>& visited, int cur) {
	if (visited[cur])
		return;
	visited[cur] = true;
	for (int i = 0; i < table[cur].size(); ++i)
		if (table[cur][i] == 1)
			DFS(table, visited, i);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string ans = "YES";
	int N, M, start = -1;
	cin >> N >> M;
	vector<vector<int>> table(N, vector<int>(N));
	deque<bool> plan(N);
	deque<bool> visited(N);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> table[i][j];

	for (int i = 0; i < M; ++i) {
		int t;
		cin >> t;
		plan[t - 1] = true;
		if (start == -1)
			start = t - 1;
	}

	DFS(table, visited, start);

	for (int i = 0; i < N; ++i)
		if (plan[i] && !visited[i]) {
			ans = "NO";
			break;
		}

	cout << ans;

	return 0;
}