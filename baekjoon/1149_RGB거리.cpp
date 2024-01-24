#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<vector<int>> dp(N, vector<int>(3));
	for (int i = 0; i < N; ++i) {
		int r, g, b;
		cin >> r >> g >> b;
		if (i == 0) {
			dp[0][0] = r;
			dp[0][1] = g;
			dp[0][2] = b;
		}
		else {
			dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + r;
			dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + g;
			dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + b;
		}
	}
	cout << min(dp[N - 1][0], min(dp[N - 1][1], dp[N - 1][2]));
	return 0;
}