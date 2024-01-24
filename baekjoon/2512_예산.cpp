#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int N, int M,int maxValue, vector<int>& budget) {
	int ans = -1;
	int bottom = 1, top = maxValue, mid;
	while (bottom <= top) {
		int sum = 0;
		mid = (bottom + top) / 2;
		for (int i = 0; i < N; ++i) {
			if (mid < budget[i])
				sum += mid;
			else
				sum += budget[i];
		}
		if (sum > M)
			top = mid - 1;
		else {
			bottom = mid + 1;
			ans = mid;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M, sum = 0, maxValue = 0;
	cin >> N;
	vector<int> budget(N);
	for (int i = 0; i < N; ++i) {
		cin >> budget[i];
		sum += budget[i];
		maxValue = max(maxValue, budget[i]);
	}
	cin >> M;
	if (sum <= M)
		cout << maxValue;
	else
		cout << solve(N, M, maxValue, budget);
	return 0;
}