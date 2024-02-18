#include <iostream>
#include <cmath>
#include <vector>
#include <deque>

using namespace std;

int n, answer = 0;

vector<vector<int>> edge;
vector<int> ball;
deque<bool> visited;

int dfs(int cur) {
	visited[cur] = true;

	for (int i = 0; i < edge[cur].size(); ++i) {
		int next = edge[cur][i];
		if (!visited[next])
			ball[cur] += dfs(next);
	}

	answer += abs(ball[cur] - 1);
	return ball[cur] - 1;
}

void resetValue() {
	answer = 0;
	edge.clear();
	ball.clear();
	visited.clear();
	edge.resize(n + 1);
	ball.resize(n + 1);
	visited.resize(n + 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	while (true) {
		cin >> n;
		if (n == 0)
			return 0;

		resetValue();

		for (int i = 0; i < n; ++i) {
			int v, c, d;
			cin >> v >> c >> d;
			ball[v] = c;
			for (int j = 0; j < d; ++j) {
				int t;
				cin >> t;
				edge[v].push_back(t);
				edge[t].push_back(v);
			}
		}
		dfs(1);
		cout << answer << endl;
	}
	return 0;
}