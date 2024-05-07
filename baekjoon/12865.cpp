#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	vector<int> dp(K + 1);
	for (int i = 0; i < N; ++i) {
		int W, V;
		cin >> W >> V;
		for (int j = K - W; j >= 0; --j)
			dp[j + W] = max(dp[j + W], dp[j] + V);
	}
	cout << dp[K];

	return 0;
}