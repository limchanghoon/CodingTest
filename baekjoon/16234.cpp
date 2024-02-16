#include <iostream>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int dr[4] = { -1,+1,+0,+0 };
int dc[4] = { +0,+0,-1,+1 };
int N, L, R;
int table[50][50];
bool visited[50][50];
queue<pair<int,int>> q;

void resetVisited() {
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			visited[i][j] = false;
}

bool CheckVaild(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= N)
		return false;
	return true;
}
bool CheckBorder(int r1, int c1, int r2, int c2) {
	int dis = abs(table[r1][c1] - table[r2][c2]);
	if (L <= dis && dis <= R)
		return true;
	return false;
}

int dfs(int r, int c) {
	if (visited[r][c])
		return 0;
	visited[r][c] = true;
	q.push({ r,c });
	int sum = table[r][c];
	for (int i = 0; i < 4; ++i) {
		int _r = r + dr[i];
		int _c = c + dc[i];
		if (!CheckVaild(_r, _c) || visited[_r][_c])
			continue;
		if (CheckBorder(r, c, _r, _c))
			sum += dfs(_r, _c);
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L >> R;
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> table[i][j];
	int answer = -1;
	bool check = false;
	while (!check) {
		++answer;
		check = true;
		resetVisited();
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				int div = ((float)dfs(i, j) / q.size());
				if (q.size() > 1)
					check = false;
				while (!q.empty()) {
					table[q.front().first][q.front().second] = div;
					q.pop();
				}
			}
		}
	}
	cout << answer;

	return 0;
}