#include <iostream>
#include <vector>

using namespace std;

int N;
int table[10001];
int dp[10001][2];
vector<vector<int>> vec;

void dfs(int cur,int pre) {
	if (dp[cur][1] != 0)
		return;
	dp[cur][1] = table[cur];
	for (int i = 0; i < vec[cur].size(); ++i) {
		int next = vec[cur][i];
		if (next == pre)	continue;
		dfs(next, cur);

		dp[cur][0] += max(dp[next][0], dp[next][1]);
		dp[cur][1] += dp[next][0];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	vec.resize(N + 1);
	for (int i = 1; i <= N; ++i)
		cin >> table[i];
	
	for (int i = 0; i < N-1; ++i) {
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	dfs(1, -1);
	cout << max(dp[1][0], dp[1][1]);
	return 0;
}