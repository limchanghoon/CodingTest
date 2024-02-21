#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int T, N;
int node1, node2;
int answer;
bool isRoot[10001];
vector<vector<int>> vec;


int getRoot() {
	for (int i = 1; i <= N; ++i) {
		if (isRoot[i])
			return i;
	}
	return -1;
}

int dfs(int cur) {
	int sum = 0;
	if (node1 == cur)
		++sum;
	if (node2 == cur)
		++sum;
	for (int i = 0; i < vec[cur].size(); ++i) {
		sum += dfs(vec[cur][i]);
		if (sum == 2) {
			if (answer == -1)
				answer = cur;
			return 2;
		}
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N;
		answer = -1;
		memset(isRoot, true, sizeof(isRoot));
		vec.clear();
		vec.resize(N + 1);
		for (int i = 1; i < N; ++i) {
			int a, b;
			cin >> a >> b;
			vec[a].push_back(b);
			isRoot[b] = false;
		}
		cin >> node1 >> node2;
		dfs(getRoot());
		cout << answer << "\n";
	}

	return 0;
}