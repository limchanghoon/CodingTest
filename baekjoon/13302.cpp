#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

const int MAXDAY = 102;
const int MAXCOUPON = MAXDAY/2;
constexpr int MAXINT = numeric_limits<int>::max();
int N, M;
bool dayOff[MAXDAY];
int dp[MAXDAY][MAXCOUPON];

void initDP() {
	for (int i = 0; i < MAXDAY; ++i)
		for (int j = 0; j < MAXCOUPON; ++j)
			dp[i][j] = MAXINT;
}

void dfs(int day, int coupon, int cost) {

	dp[day][coupon] = cost;
	if (day > N) {
		return;
	}
	if (dayOff[day]) {
		if (cost < dp[day + 1][coupon])
			dfs(day + 1, coupon, cost);
		return;
	}

	int nextDay = min(N + 1, day + 1);
	if (coupon >= 3 && cost < dp[nextDay][coupon - 3])
		dfs(nextDay, coupon - 3, cost);

	nextDay = min(N + 1, day + 5);
	if (cost + 37000 < dp[nextDay][coupon + 2])
		dfs(nextDay, coupon + 2, cost + 37000);


	nextDay = min(N + 1, day + 3);
	if (cost + 25000 < dp[nextDay][coupon + 1])
		dfs(nextDay, coupon + 1, cost + 25000);

	nextDay = min(N + 1, day + 1);
	if (cost + 10000 < dp[nextDay][coupon])
		dfs(nextDay, coupon, cost + 10000);


}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	initDP();
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		int day;
		cin >> day;
		dayOff[day] = true;
	}

	dfs(1, 0, 0);
	int ans = MAXINT;
	for (int i = 0; i < MAXCOUPON; ++i)
		ans = min(ans, dp[N + 1][i]);
	cout << ans;

	return 0;
}