#include <iostream>

using namespace std;

int N, S;
int table[20];
int ans = 0;

void dfs(int d, int sum, int cnt) {
	if (d == N) {
		if (cnt != 0 && sum == S)
			ans++;
		return;
	}
	dfs(d + 1, sum, cnt);
	dfs(d + 1, sum + table[d], cnt + 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> S;
	for (int i = 0; i < N; ++i) {
		cin >> table[i];
	}

	dfs(0, 0, 0);

	cout << ans;

	return 0;
}