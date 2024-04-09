#include <iostream>

using namespace std;

int N, Q;
int dp[100001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int pre = 0, cur = 0;
	for (int i = 1; i <= N; ++i) {
		pre = cur;
		cin >> cur;
		dp[i] = dp[i - 1];
		if (pre > cur) ++dp[i];
	}
	cin >> Q;

	for (int i = 0; i < Q; ++i) {
		int x, y;
		cin >> x >> y;
		cout << dp[y] - dp[x] << "\n";
	}
	return 0;
}