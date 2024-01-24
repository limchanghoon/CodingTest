#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

deque<deque<bool>> visited;
vector<vector<int>> dp;
vector<vector<int>> table;

int N, M, answer = 1;

int dr[4] = { +1,-1,+0,+0 };
int dc[4] = { +0,+0,+1,-1 };

bool checkValid(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= M)
		return false;
	return true;
}

bool dfs(int r, int c, int depth) {
	visited[r][c] = true;
	int dis = table[r][c];
	++depth;
	for (int i = 0; i < 4; ++i) {
		int nextR = r + dr[i] * dis;
		int nextC = c + dc[i] * dis;
		if (checkValid(nextR, nextC)) {
			if (visited[nextR][nextC])
				return true; // °á°ú°ª -1
			if (table[nextR][nextC] != -1 && dp[nextR][nextC] < depth) {
				dp[nextR][nextC] = depth;
				answer = max(answer, depth);
				if (dfs(nextR, nextC, depth))
					return true;
			}
		}
	}
	visited[r][c] = false;
	return false;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	visited.resize(N, deque<bool>(M));
	dp.resize(N, vector<int>(M));
	table.resize(N, vector<int>(M, -1));
	for (int i = 0; i < N; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < M; ++j) {
			if (s[j] != 'H')
				table[i][j] = s[j] - '0';
		}
	}

	if (dfs(0, 0, 1))
		cout << -1;
	else
		cout << answer;
	return 0;
}