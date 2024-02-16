#include <iostream>

using namespace std;

long long dp[1000001] = { 1,2,7,22 };

int solve(int N) {
	if (N <= 3)
		return dp[N];

	long long sum = dp[0];
	for (int i = 4; i <= N; ++i) {
		sum += dp[i - 3] % 1000000007;
		dp[i] = (2 * dp[i - 1] + 3 * dp[i - 2] + 2 * sum) % 1000000007;
	}
	return dp[N];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, answer = 0;
	cin >> N;

	cout << solve(N);

	return 0;
}