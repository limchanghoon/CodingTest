#include <iostream>
#include <vector>

using namespace std;

int N;
bool visited[100];
int answer[100][100];
vector<vector<int>> table;

void dfs(int base, int cur) {
	for (int i = 0; i < table[cur].size(); ++i) {
		int next = table[cur][i];
		if (visited[next])
			continue;
		visited[next] = true;
		answer[base][next] = 1;
		dfs(base, next);
	}
}

void resetVisited() {
	for (int i = 0; i < N; ++i)
		visited[i] = false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	table.resize(N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int temp;
			cin >> temp;
			if (temp == 1)
				table[i].push_back(j);
		}
	}

	for (int i = 0; i < N; ++i) {
		if (table[i].size() == 0)
			continue;
		resetVisited();
		dfs(i, i);
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j)
			cout << answer[i][j] << " ";
		cout << "\n";
	}
	return 0;
}