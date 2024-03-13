#include <iostream>
#include <cstring>

using namespace std;

int input[10];
int dp[10][6][6][10];

int solve(int d, int ppre, int pre, int score) {
	if (d == 10) {
		if (score >= 5) return 1;
		return 0;
	}
	if (dp[d][ppre][pre][score] != -1)
		return dp[d][ppre][pre][score];

	int ret = 0;
	for (int i = 1; i <= 5; ++i) {
		if (ppre == i && pre == i)
			continue;
		if (input[d] == i) ret += solve(d + 1, pre, i, score + 1);
		else ret += solve(d + 1, pre, i, score);
	}
	dp[d][ppre][pre][score] = ret;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 10; ++i) {
		cin >> input[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0, 0, 0);
	return 0;
}