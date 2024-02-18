#include <iostream>
#include <cstring>

using namespace std;

int N;
int table[5];
long long dp[11][11][11][11][11][6][6];

long long solve(int cnt1, int cnt2, int cnt3, int cnt4, int cnt5, int ppre, int pre) {
	if (cnt1 + cnt2 + cnt3 + cnt4 + cnt5 == 0)	return 1;
	if (dp[cnt1][cnt2][cnt3][cnt4][cnt5][ppre][pre] != -1)
		return dp[cnt1][cnt2][cnt3][cnt4][cnt5][ppre][pre];
	long long sum = 0;
	
	if (cnt1 > 0 && ppre != 1 && pre != 1)	sum += solve(cnt1 - 1, cnt2, cnt3, cnt4, cnt5, pre, 1);
	if (cnt2 > 0 && ppre != 2 && pre != 2)	sum += solve(cnt1, cnt2 - 1, cnt3, cnt4, cnt5, pre, 2);
	if (cnt3 > 0 && ppre != 3 && pre != 3)	sum += solve(cnt1, cnt2, cnt3 - 1, cnt4, cnt5, pre, 3);
	if (cnt4 > 0 && ppre != 4 && pre != 4)	sum += solve(cnt1, cnt2, cnt3, cnt4 - 1, cnt5, pre, 4);
	if (cnt5 > 0 && ppre != 5 && pre != 5)	sum += solve(cnt1, cnt2, cnt3, cnt4, cnt5 - 1, pre, 5);
	
	dp[cnt1][cnt2][cnt3][cnt4][cnt5][ppre][pre] = sum;

	return sum;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> table[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << solve(table[0], table[1], table[2], table[3], table[4], 0, 0);

	return 0;
}