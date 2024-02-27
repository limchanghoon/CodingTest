#include <iostream>

using namespace std;

int N;
int dp[101][11];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i <= 9; ++i) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= N; ++i) {
		dp[i][0] = dp[i - 1][1];
		for (int j = 1; j <= 9; ++j) {
			dp[i][j] = (dp[i - 1][j - 1] % 1000000000 + dp[i - 1][j + 1] % 1000000000) % 1000000000;
		}
	}
	int answer = 0;
	for (int i = 1; i <= 9; ++i) {
		answer = (answer + dp[N][i]) % 1000000000;
	}
	cout << answer;
	return 0;
}