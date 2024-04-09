#include <iostream>
#include <algorithm>

using namespace std;

int dp[10001][501];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;
		for (int j = 0; j <= M; ++j) {
			if (j + 1 <= M)
				dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + temp);
			if (i + j <= N)
				dp[i + j][0] = max(dp[i + j][0], dp[i][j]);
		}
		if (i + 1 <= N)
			dp[i + 1][0] = max(dp[i + 1][0], dp[i][0]);
	}

	cout << dp[N][0];

	return 0;
}