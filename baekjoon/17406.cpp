#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

struct Rot {
	int r, c, s;
};

int N, M, K, ans = numeric_limits<int>::max();
int order[6] = { -1,-1,-1,-1,-1,-1 };
bool visited[6];
vector<vector<int>> init_table;
vector<vector<int>> table;
vector<Rot> rots;

int getMinSum() {
	int result = numeric_limits<int>::max();
	for (int i = 0; i < N; ++i) {
		int sum = 0;
		for (int j = 0; j < M; ++j)
			sum += table[i][j];
		result = min(result, sum);
	}
	return result;
}

void rotate(int r, int c, int s) {
	if (s == 0)
		return;
	int startR = r - s - 1, startC = c - s - 1;
	int endR = r + s - 1, endC = c + s - 1;
	int temp = table[startR][startC];
	for (int i = startR + 1; i <= endR; ++i)
		table[i - 1][startC] = table[i][startC];
	for (int i = startC + 1; i <= endC; ++i)
		table[endR][i - 1] = table[endR][i];
	for (int i = endR - 1; i >= startR; --i)
		table[i + 1][endC] = table[i][endC];
	for (int i = endC - 1; i >= startC; --i)
		table[startR][i + 1] = table[startR][i];
	table[startR][startC + 1] = temp;

	rotate(r, c, s - 1);
}

void permutation(int depth) {
	if (depth == K) {
		table.assign(init_table.begin(), init_table.end());
		for (int i = 0; i < K; ++i) {
			int idx = order[i];
			rotate(rots[idx].r, rots[idx].c, rots[idx].s);
		}
		ans = min(ans, getMinSum());
		return;
	}
	for (int i = 0; i < K; ++i) {
		if (!visited[i]) {
			order[depth] = i;
			visited[i] = true;
			permutation(depth + 1);
			visited[i] = false;
			order[depth] = -1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	init_table.resize(N, vector<int>(M));
	table.resize(N, vector<int>(M));
	rots.resize(K);
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j)
			cin >> init_table[i][j];
	for (int i = 0; i < K; ++i)
		cin >> rots[i].r >> rots[i].c >> rots[i].s;
	permutation(0);
	cout << ans;
	return 0;
}