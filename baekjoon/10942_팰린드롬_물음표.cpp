#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N,M;
	cin >> N;
	vector<int> inputs(N+1);
	vector<deque<bool>> dp(N + 1, deque<bool>(N + 1));
	for (int i = 1; i <= N; ++i)
		cin >> inputs[i];

	// 1°³,2°³ 
	for (int i = 1; i < N; ++i) {
		dp[i][i] = true;
		if (inputs[i] == inputs[i + 1])
			dp[i][i + 1] = true;
	}
	dp[N][N] = true;

	// 3~N °³
	for (int len = 3; len <= N; ++len)
		for (int i = 1; i + len - 1 <= N; ++i)
			if (inputs[i] == inputs[i + len - 1] && dp[i + 1][i + len - 2])
				dp[i][i + len - 1] = true;
		
	cin >> M;
	while(M--){
		int start, end;
		cin >> start >> end;
		cout << dp[start][end] << "\n";
	}
	return 0;
}