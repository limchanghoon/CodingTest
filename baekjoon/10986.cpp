#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<int> dp(M);
	long long ans = 0;
	long long sum = 0;
	for (int i = 0; i < N; ++i) {
		long long temp;
		cin >> temp;
		sum += temp;
		if (sum % M == 0)
			ans++;
		ans += dp[sum % M];
		dp[sum % M]++;
	}

	cout << ans;

	return 0;
}