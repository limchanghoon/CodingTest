#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// 0: 불포함, 1: 포함
int dp[201][2];
int atom[201];
int proton[201];

vector<vector<int>> table;

void dfs(int index, int pre) {
	int exclude = 0;
	int include = atom[index];

	for (int i = 0; i < table[index].size(); ++i) {
		int next = table[index][i];
		if (next != pre)
			dfs(next, index);
		exclude += max(dp[next][0], dp[next][1]);
		include += dp[next][0];
	}

	dp[index][0] = exclude;
	dp[index][1] = include;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	table.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> atom[i];
	}

	for (int i = 0; i < M; ++i) {
		cin >> proton[i];
	}

	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			for (int k = 0; k < M; ++k) {
				if (abs(atom[i] - atom[j]) == proton[k]) {
					table[i].push_back(j);
					table[j].push_back(i);
				}
			}
		}
	}

	dfs(0, -1);

	cout << max(dp[0][0], dp[0][1]);

	return 0;
}