#include <iostream>

using namespace std;

long long N, R, C, ans;

bool check(long long r, long long c, long long M) {
	if (r <= R && R <= r + M - 1 && c <= C && C <= c + M - 1) return true;
	return false;
}

bool dfs(long long r, long long c, long long M) {
	if (M == 1) {
		if (r == R && c == C) return true;
		++ans;
		return false;
	}
	M /= 2;
	long long MM = M * M;
	if (check(r, c, M)) {
		if (dfs(r, c, M)) return true;
	}
	else ans += MM;

	if (check(r, c + M, M)) {
		if (dfs(r, c + M, M)) return true;
	}
	else ans += MM;

	if (check(r + M, c, M)) {
		if (dfs(r + M, c, M)) return true;
	}
	else ans += MM;

	if (check(r + M, c + M, M)) {
		if (dfs(r + M, c + M, M)) return true;
	}
	else ans += MM;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	ans = 0;
	cin >> N >> R >> C;
	long long M = 1 << N;
	dfs(0, 0, M);
	cout << ans;
	return 0;
}