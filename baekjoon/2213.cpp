#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MYMAX 10001

int dp[MYMAX][2];
int costs[MYMAX];
bool visited[MYMAX];
vector<vector<int>> edges;
vector<int> results;
int n;

void dfs(int cur) {
	visited[cur] = true;
	int included = costs[cur];
	int excluded = 0;
	for (int i = 0; i < edges[cur].size(); ++i) {
		int next = edges[cur][i];
		if (visited[next])
			continue;
		dfs(next);
		included += dp[next][1];
		excluded += max(dp[next][0], dp[next][1]);
	}
	dp[cur][0] = included;
	dp[cur][1] = excluded;
}

void backtrace(int cur, bool included) {
	visited[cur] = true;
	if (!included && dp[cur][0] > dp[cur][1]) {
		results.push_back(cur);
		included = true;
	}
	else
		included = false;

	for (int i = 0; i < edges[cur].size(); ++i) {
		int next = edges[cur][i];
		if (visited[next])
			continue;
		backtrace(next, included);
	}
}

void resetVisited() {
	for (int i = 1; i <= n; ++i)
		visited[i] = false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	edges.resize(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> costs[i];

	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a>>b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}

	// 최대값 찾기
	dfs(1);
	cout << max(dp[1][0], dp[1][1]) << "\n";

	// 최대값에 해당하는 원소들 찾기
	resetVisited();
	backtrace(1, false);
	sort(results.begin(), results.end());
	for (int i = 0; i < results.size(); ++i)
		cout << results[i] << " ";

	return 0;
}