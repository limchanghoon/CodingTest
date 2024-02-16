#include <iostream>
#include <vector>
#include <deque>
#include <cfloat>

using namespace std;

int N, M, T;
vector<vector<int>> table;
deque<deque<bool>> visited;
vector<int> tempTable;

constexpr int dr[] = { +1,-1,+0,+0 };
constexpr int dc[] = { +0,+0,+1,-1 };

int setPos(int c) {
	while (c < 0) {
		c += M;
	}
	c %= M;

	return c;
}

void rotate() {
	int x, d, k;
	cin >> x >> d >> k;

	for (int i = x - 1; i < N; i += x) {
		for (int j = 0; j < M; ++j) {
			int des;
			if (d == 0)
				des = setPos(j + k);
			else
				des = setPos(j - k);
			tempTable[des] = table[i][j];
		}
		table[i] = tempTable;
	}
}

bool deleteDFS(int r, int c, int value, int depth) {
	if (visited[r][c])
		return false;
	visited[r][c] = true;

	if (depth > 0)
		table[r][c] = 0;

	bool del = false;
	for (int i = 0; i < 4; ++i) {
		int nextR = r + dr[i];
		int nextC = setPos(c + dc[i]);

		if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= M)
			continue;
		if (table[nextR][nextC] != value)
			continue;
		deleteDFS(nextR, nextC, value, depth + 1);
		del = true;
	}
	return del;
}

void initVisited() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			visited[i][j] = false;
		}
	}
}

bool remove() {
	bool del = false;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (table[i][j] != 0) {
				if (deleteDFS(i, j, table[i][j], 0)) {
					table[i][j] = 0;
					del = true;
				}
			}
		}
	}

	return del;
}

bool plus_minus() {
	float avg = 0.0f;
	int count = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (table[i][j] == 0)
				continue;
			avg += table[i][j];
			++count;
		}
	}
	if (count == 0)
		return false;
	avg /= count;

	// +-1
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (table[i][j] == 0)
				continue;

			float dis = avg - table[i][j];
			if (abs(dis) <= FLT_EPSILON)
				continue;

			if (dis > 0)
				++table[i][j];
			else if (dis < 0)
				--table[i][j];
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> T;
	table.resize(N, vector<int>(M));
	visited.resize(N, deque<bool>(M));
	tempTable.resize(M);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> table[i][j];
		}
	}

	while (T--) {
		rotate();
		initVisited();
		if (remove())
			continue;
		if (!plus_minus())
			break;
	}


	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			ans += table[i][j];
		}
	}
	cout << ans;

	return 0;
}