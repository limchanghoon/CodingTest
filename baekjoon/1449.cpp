#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, L;
	cin >> N >> L;
	vector<int> table(N);
	for (int i = 0; i < N; ++i) {
		cin >> table[i];
	}

	sort(table.begin(), table.end());

	int ans = 0;
	int sum = 0;
	for (int i = 0; i < N; ++i) {
		if (sum >= table[i]) continue;
		ans++;
		sum = table[i] + L - 1;
	}
	cout << ans;

	return 0;
}