#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> table(N + 1, vector<int>(M + 1));
	vector<vector<int>> dp(N + 1, vector<int>(M + 1));
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j) 
			cin >> table[i][j];

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			dp[i][j] = max(max(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + table[i][j];

	cout << dp[N][M];
	return 0;
}