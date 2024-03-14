#include <iostream>

using namespace std;

int N, S, M;
int table[50];
int dp[51][1001];

void dfs(int d, int V) {
	if (d == N) dp[d][V] = 1;
	if (dp[d][V] == 1) return;
	dp[d][V] = 1;

	int a = V - table[d];
	int b = V + table[d];

	if (0 <= a && a <= M) {
		dfs(d + 1, a);
	}
	if (0 <= b && b <= M) {
		dfs(d + 1, b);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> S >> M;
	for (int i = 0; i < N; ++i) {
		cin >> table[i];
	}

	dfs(0, S);
	
	for (int i = M; i >= 0; --i) {
		if (dp[N][i] == 1) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
	return 0;
}