#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>

using namespace std;

bool dfs(int cur, int target, int cost, vector<vector<pair<int, int>>>& table, deque<bool>& visited) {
	if (visited[cur]) return false;
	visited[cur] = true;

	if (cur == target) {
		cout << cost << "\n";
		return true;
	}

	for (int i = 0; i < table[cur].size(); ++i) {
		if (dfs(table[cur][i].first, target, cost + table[cur][i].second, table, visited))
			return true;
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<vector<pair<int,int>>> table(N + 1);
	deque<bool> visited(N + 1);
	for (int i = 0; i < N - 1; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		table[a].push_back({ b, c });
		table[b].push_back({ a, c });
	}
	for (int i = 0; i < M; ++i) {
		fill(visited.begin(), visited.end(), false);
		int A, B;
		cin >> A >> B;
		dfs(A, B, 0, table, visited);
	}

	return 0;
}