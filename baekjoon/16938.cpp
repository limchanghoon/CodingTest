#include <iostream>
#include <algorithm>

using namespace std;

int N, L, R, X;
int answer = 0;
int problems[15];
bool pick[15];

void dfs(int depth) {

	if (depth == N) {
		int sum = 0;
		int minV = 99999999;
		int maxV = -99999999;
		for (int i = 0; i < N; ++i) {
			if (!pick[i]) continue;
			sum += problems[i];
			minV = min(minV, problems[i]);
			maxV = max(maxV, problems[i]);
		}
		if (sum != 0 && maxV - minV >= X && L <= sum && sum <= R)
			answer++;
		return;
	}

	pick[depth] = true;
	dfs(depth + 1);
	pick[depth] = false;
	dfs(depth + 1);
}

int solve() {
	dfs(0);
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> L >> R >> X;
	for (int i = 0; i < N; ++i) {
		cin >> problems[i];
	}
	cout << solve();

	return 0;
}