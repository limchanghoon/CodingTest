#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	vector<vector<long long>> dp(100001, vector<long long>(2));
	dp[1][0] = 1; dp[1][1] = 0;
	dp[2][0] = 1; dp[2][1] = 1;
	dp[3][0] = 2; dp[3][1] = 2;
	for (int i = 4; i <= 100000; ++i) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 2][1] + dp[i - 3][1]) % 1000000009;
		dp[i][1] = (dp[i - 1][0] + dp[i - 2][0] + dp[i - 3][0]) % 1000000009;
	}

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		cout << dp[n][0] << " " << dp[n][1] << "\n";
	}

	return 0;
}