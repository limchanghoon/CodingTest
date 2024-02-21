#include <iostream>

using namespace std;

int dp[6][6][2];
char table[6][6];

int N;

void dfs(int r, int c, int num, char op) {
	if (r <= 0 || r > N || c <= 0 || c > N)	return;

	int sum = r + c;
	// 숫자
	if (sum % 2 == 0) {
		int _num = table[r][c] - '0';
		if (op == '+')
			num += _num;
		else if (op == '-')
			num -= _num;
		else
			num *= _num;
	}

	bool isReturn = true;
	if (dp[r][c][0] < num) {
		dp[r][c][0] = num;
		isReturn = false;
	}
	if (dp[r][c][1] > num) {
		dp[r][c][1] = num;
		isReturn = false;
	}
	if (isReturn)	return;

	// 연산자
	if (sum % 2 == 1) {
		op = table[r][c];
	}

	dfs(r + 1, c, num, op);
	dfs(r, c + 1, num, op);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			char t;
			cin >> t;
			table[i][j] = t;
			dp[i][j][0] = -99999999;
			dp[i][j][1] = 99999999;
		}
	}

	dfs(1, 1, 0, '+');

	cout << dp[N][N][0] << " " << dp[N][N][1];
	return 0;
}