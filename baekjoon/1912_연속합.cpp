#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	int ans = numeric_limits<int>::min();
	cin >> N;
	vector<int> dp(N);
	for (int i = 0; i < N; ++i)
	{
		int temp;
		cin >> temp;
		if (i == 0)
			dp[i] = temp;
		else
			dp[i] = max(dp[i - 1] + temp, temp);
		ans = max(ans, dp[i]);
	}
	cout << ans;
	return 0;
}