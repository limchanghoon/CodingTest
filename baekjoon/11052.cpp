#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> dp(N + 1);
	for (int i = 1; i <= N; ++i)
		cin >> dp[i];

	for (int i = 1; i < N; ++i)
		for (int j = 1; i + j <= N; ++j)
			dp[i + j] = max(dp[i + j], dp[i] + dp[j]);

	cout << dp[N];
	return 0;
}