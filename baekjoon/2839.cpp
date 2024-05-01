#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> dp(max(6, N + 1));
	dp[1] = -1;
	dp[2] = -1;
	dp[3] = 1;
	dp[4] = -1;
	dp[5] = 1;

	for (int i = 6; i <= N; ++i) {
		if (dp[i - 3] == -1 && dp[i - 5] == -1) {
			dp[i] = -1;
		}
		else {
			int i3 = dp[i - 3] == -1 ? 999999 : dp[i - 3] + 1;
			int i5 = dp[i - 5] == -1 ? 999999 : dp[i - 5] + 1;
			dp[i] = min(i3, i5);
		}
	}

	cout << dp[N];

	return 0;
}