#include <iostream>
#include <algorithm>

using namespace std;

int N, k;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> k;
	int answer = -1;
	int left = 1, right = 1000000000, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		int cnt = 0;
		for (int i = 1; i <= N; ++i) {
			cnt += min(mid / i, N);
		}
		if (cnt >= k) {
			answer = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << answer;

	return 0;
}