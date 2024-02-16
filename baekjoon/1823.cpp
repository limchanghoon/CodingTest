#include <iostream>
#include <algorithm>

using namespace std;

int rice[2000];
int dp[2000][2000];

int solve(int left, int right, int count) {
	if (left > right)	return 0;
	if (dp[left][right] != 0)	return dp[left][right];

	int answer = max(solve(left + 1, right, count + 1) + count * rice[left], solve(left, right - 1, count + 1) + count * rice[right]);

	return dp[left][right] = answer;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int answer = 0;

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> rice[i];
	}
	cout << solve(0, N - 1, 1);
	return 0;
}


/*
* 첫 번째 풀이 : 가독성이 떨어짐
* 
#include <iostream>
#include <algorithm>

using namespace std;

int N;
int rice[2001];
int dp[2001][2001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int answer = 0;

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> rice[i];
	}

	for (int i = 1; i <= N; ++i) {
		for (int left = 1; left <= i; ++left) {
			int right = N - i + left;
			dp[left + 1][right] = max(dp[left + 1][right], dp[left][right] + i * rice[left]);			// 왼쪽 제거
			dp[left][right - 1] = max(dp[left][right - 1], dp[left][right] + i * rice[right]);			// 오른쪽 제거
			if (left == right) {
				answer = max(answer, max(dp[left + 1][right], dp[left][right - 1]));
			}
		}
	}

	cout << answer;
	return 0;
}
*/