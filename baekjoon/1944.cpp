#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct MyStruct {
	int cost, A, B;
};

struct CMP {
	bool operator()(const MyStruct& A, const MyStruct& B) {
		return A.cost > B.cost;
	}
};

const int dr[4] = { +1,-1,+0,+0 };
const int dc[4] = { +0,+0,+1,-1 };

int N, M;
bool visited[51][51];
vector<vector<char>> table;
int parent[2501];
priority_queue<MyStruct, vector<MyStruct>, CMP> pq;

bool isValid(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= N) return false;
	return true;
}

void bfs(int sr, int sc) {
	queue<pair<int, pair<int, int>>> q;
	visited[sr][sc] = true;
	q.push({ 0,{sr,sc} });

	while (!q.empty()) {
		int cost = q.front().first;
		int r = q.front().second.first;
		int c = q.front().second.second;
		q.pop();

		if (cost != 0 && (table[r][c] == 'S' || table[r][c] == 'K')) {
			pq.push({ cost, sr * N + sc, r * N + c });
		}

		for (int i = 0; i < 4; ++i) {
			int nextR = r + dr[i];
			int nextC = c + dc[i];
			if (isValid(nextR, nextC) && table[nextR][nextC] != '1' && !visited[nextR][nextC]) {
				visited[nextR][nextC] = true;
				q.push({ cost + 1, {nextR, nextC} });
			}
		}
	}
}

int getParent(int x) {
	if (x == parent[x]) return x;
	return parent[x] = getParent(parent[x]);
}

void merge(int x, int y) {
	int px = getParent(x);
	int py = getParent(y);

	if (px < py) parent[py] = px;
	else parent[px] = py;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	vector<vector<int>> cost(N, vector<int>(N));
	table.resize(N, vector<char>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> table[i][j];
			parent[i * N + j] = i * N + j;
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (table[i][j] == 'K' || table[i][j] == 'S') {
				memset(visited, false, sizeof(visited));
				bfs(i, j);
			}
		}
	}

	int ans = 0;
	while (!pq.empty()) {
		int a = pq.top().A;
		int b = pq.top().B;
		int cost = pq.top().cost;
		pq.pop();

		if (getParent(a) == getParent(b)) continue;
		merge(a, b);
		ans += cost;
		if (--M == 0) break;
	}

	if (M > 0) cout << -1;
	else cout << ans;

	return 0;
}