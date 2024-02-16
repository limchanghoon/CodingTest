#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

const int dx[] = {+0,+0,-1,+1};
const int dy[] = {-1,+1,+0,+0};

int innerDFS(int r, int c, int height, vector<vector<int>>& table, deque<deque<bool>>& visited) {
	int N = table.size();
	if (r < 0 || r >= N || c < 0 || c >= N)
		return 0;
	if (visited[r][c] || table[r][c] <= height)
		return 0;
	visited[r][c] = true;

	int count = 1;
	for (int i = 0; i < 4; ++i)
		count += innerDFS(r + dx[i], c + dy[i], height, table, visited);
	return count;
}

int DFS(int height, vector<vector<int>>& table) {
	int N = table.size(), ans = 0;
	deque<deque<bool>> visited(N, deque<bool>(N));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			if (innerDFS(i, j, height, table, visited) > 0)
				++ans;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, ans = 0;;
	cin >> N;
	vector<vector<int>> table(N, vector<int>(N));
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> table[i][j];

	for (int i = 0; i < 100; ++i) {
		int temp = DFS(i, table);
		ans = max(ans, temp);
		if (temp == 0)
			break;
	}
	cout << ans;
	return 0;
}