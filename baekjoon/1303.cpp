#include <iostream>
#include <vector>

using namespace std;

int dfs(int r, int c, vector<vector<char>>& table, vector<vector<int>>& visited, char T) {
	if (r < 0 || r >= table.size() || c < 0 || c >= table[0].size() || visited[r][c] == 1) return 0;
	if (table[r][c] != T) return 0;
	visited[r][c] = 1;

	const int dr[4] = { +1,-1,+0,+0 };
	const int dc[4] = { +0,+0,+1,-1 };

	int sum = 1;
	for (int i = 0; i < 4; ++i) {
		sum += dfs(r + dr[i], c + dc[i], table, visited, T);
	}

	return sum;
}

int getPower(vector<vector<char>>& table, vector<vector<int>>& visited, char T) {
	int M = table.size(), N = table[0].size();
	int ans = 0;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			int temp = dfs(i, j, table, visited, T);
			ans += temp * temp;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<vector<char>> table(M, vector<char>(N));
	vector<vector<int>> visited(M, vector<int>(N));
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> table[i][j];
		}
	}

	cout << getPower(table, visited, 'W') << " " << getPower(table, visited, 'B');
	return 0;
}