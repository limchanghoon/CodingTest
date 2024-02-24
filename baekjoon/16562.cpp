#include <iostream>
#include <algorithm>


using namespace std;

int N, M, K;

int cost[10001];
int parent[10001];
bool visited[10001];

int find(int a) {
	if (parent[a] == a)	return a;
	else return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
	int pa = find(a);
	int pb = find(b);

	if (cost[pa] > cost[pb])	parent[pa] = pb;
	else parent[pb] = pa;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; ++i) {
		cin >> cost[i];
		parent[i] = i;
	}

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}

	int sum = 0;
	for (int i = 1; i <= N; ++i) {
		int a = find(i);
		if (visited[a]) continue;
		visited[a] = true;
		sum += cost[a];
	}

	if (sum > K) cout << "Oh no";
	else cout << sum;

	return 0;
}


/*
* 첫번째 풀이 DFS
* 
#include <iostream>
#include <vector>
#include <algorithm>

#define FAIL 99999999

using namespace std;

int N, M, K;

int table[10001];
bool visited[10001];
vector<vector<int>> relations;

int dfs(int cur) {
	if (visited[cur])	return FAIL;
	visited[cur] = true;

	int minK = table[cur];
	for (int i = 0; i < relations[cur].size(); ++i) {
		minK = min(minK, dfs(relations[cur][i]));
	}
	return minK;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;
	relations.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> table[i];
	}

	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		relations[a].push_back(b);
		relations[b].push_back(a);
	}

	int sum = 0;
	for (int i = 1; i <= N; ++i) {
		int temp = dfs(i);
		if (temp != FAIL)
			sum += temp;
	}
	
	if (sum > K)
		cout << "Oh no";
	else
		cout << sum;

	return 0;
}
*/