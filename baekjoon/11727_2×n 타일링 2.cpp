#include <iostream>

using namespace std;

int dp[1001] = { 0, 1,3,5,11, };

int main() {
	int n;
	cin >> n;
	for (int i = 4; i <= n; ++i)
		dp[i] = (dp[i - 1] + dp[i - 2] * 2) % 10007;
	cout << dp[n];
	return 0;
}