#include <iostream>

using namespace std;

int N, M;
long long table[2000][2000];
long long dp[2000][2000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	int M2 = M / 2;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> table[i][j];
			table[i][j] *= -1;
		}
	}

	if (M == 1) {
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cout << table[i][j] << " ";
			}
			cout << "\n";
		}
		return 0;
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int r1 = i + M2 < N ? i + M2 : N - 1;
			int c1 = j + M2 < N ? j + M2 : N - 1;
			int r2 = i - M2 - 1 >= 0 ? i - M2 - 1 : 0;
			int c2 = j - M2 - 1 >= 0 ? j - M2 - 1 : 0;

			dp[r1][c1] = dp[r1][c2] + dp[r2][c1] - dp[r2][c2] + table[i][j];
		}
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int r1 = i - 1 < 0 ? 0 : i - 1;
			int c1 = j - 1 < 0 ? 0 : j - 1;
			cout << dp[i][j] - dp[r1][j] - dp[i][c1] + dp[r1][c1] << " ";
		}
		cout << "\n";
	}

	return 0;
}