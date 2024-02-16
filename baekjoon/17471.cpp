#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

int N, sum = 0, ans = numeric_limits<int>::max();
vector<int> populations;
vector<vector<int>> adjacency;
vector<int> visited;
deque<bool> contains;

void innerBFS(queue<int>& q,int start, bool team) {
	visited[start] = team;
	q.push(start);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < adjacency[cur].size(); ++i) {
			int next = adjacency[cur][i];
			if (contains[next] == team && visited[next] == -1) {
				visited[next] = team;
				q.push(next);
			}
		}
	}
}

void BFS(int start1, int start2) {
	queue<int> q;
	for (int i = 0; i < N; ++i)
		visited[i] = -1;

	innerBFS(q, start1, true);	// 선거구 1 찾기
	innerBFS(q, start2, false);	// 선거구 2 찾기

	int sum1 = 0;
	for (int i = 0; i < N; ++i) {
		if (visited[i] == -1)// 선거구 없는 곳 있음!
			return;
		else if (visited[i] == 1)
			sum1 += populations[i];
	}
	ans = min(ans, abs(sum - 2*sum1));
}

int getStart2() {
	for (int i = 0; i < N; ++i)
		if (!contains[i])
			return i;
}

void combination(int start, int depth) {
	if (depth > N / 2)
		return;

	for (int i = start; i < N; ++i) {
		contains[i] = true;
		BFS(i, getStart2());
		combination(i + 1, depth + 1);
		contains[i] = false;
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	populations.resize(N);
	adjacency.resize(N);
	visited.resize(N);
	contains.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> populations[i];
		sum += populations[i];
	}
	for (int i = 0; i < N; ++i) {
		int n;
		cin >> n;
		for (int j = 0; j < n; ++j) {
			int t;
			cin >> t;
			adjacency[i].push_back(t-1);
		}
	}

	combination(0, 1);
	if (ans == numeric_limits<int>::max())
		ans = -1;
	cout << ans;

	return 0;
}