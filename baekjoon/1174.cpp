/*
* 처음 풀이 DP
* 
#include <iostream>
#include <vector>

using namespace std;

int dp[10][10];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	long long ans = 0;
	int N;
	cin >> N;

	for (int i = 0; i <= 9; i++) 
		dp[0][i] = 1;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
		}
	}

	int temp = N;
	for (int i = 0; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			temp -= dp[i][j];
			if (temp <= 0) {
				ans *= 10;
				ans += j;
				temp += dp[i][j];
				if (i == 0) {
					cout << ans;
					return 0;
				}
				i = i - 2;
				break;
			}
		}
	}

	cout << "-1";

	return 0;
}
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> table;

void backtracking(long long start, long long num) {
	for (long long i = start; i >= 0; --i) {
		long long newNum = num * 10 + i;
		table.push_back(newNum);
		backtracking(i - 1, newNum);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	backtracking(9, 0);
	sort(table.begin(), table.end());

	int n;
	cin >> n;

	if (table.size() < n) cout << -1;
	else cout << table[n - 1];
	
	return 0;
}