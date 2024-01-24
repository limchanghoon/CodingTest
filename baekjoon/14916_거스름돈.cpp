#include <iostream>
#include <algorithm>

using namespace std;

//10까지 미리 계산
int dp[100001] = { 0,0,1,0,2,1,3,2,4,3,2, };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 11; i <= n; ++i)
		dp[i] = min(dp[i - 2] + 1, dp[i - 5] + 1);

	cout << ((dp[n] == 0) ? -1 : dp[n]);
	return 0;
}