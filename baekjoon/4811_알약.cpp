#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (true) {
		int N;
		cin >> N;
		if (N == 0)
			return 0;
		vector<vector<long long>> dp(N+1, vector<long long>(N+1));

		dp[N][0] = 1;
		for (int i = N - 1; i >= 0; --i) {
			for (int j = N - i; j >= 0; --j)
				if (j == 0)
					dp[i][j] = dp[i][j + 1];
				else if (j == N)
					dp[i][j] = dp[i + 1][j - 1];
				else
					dp[i][j] = dp[i + 1][j - 1] + dp[i][j + 1];
		}
		cout << dp[0][0] << "\n";
	}
	return 0;
}