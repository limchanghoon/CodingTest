#include <iostream>
#include <algorithm>

#pragma warning( disable : 6385 ) 

using namespace std;

int n;

int table[10000];
int dp[10000][3];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> table[i];
	}

	dp[0][1] = table[0];
	for (int i = 1; i < n; ++i) {
		dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));
		dp[i][1] = dp[i - 1][0] + table[i];
		dp[i][2] = dp[i - 1][1] + table[i];
	}

	cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));

	return 0;
}