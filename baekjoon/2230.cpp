#include <iostream>
#include <algorithm>
#include <vector>
#include <limits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M, ans = numeric_limits<int>::max();
	cin >> N >> M;
	vector<int> table(N);
	for (int i = 0; i < N; ++i) {
		cin >> table[i];
	}
	sort(table.begin(), table.end());
	for (int p1 = 0, p2 = 0; p1 < N && p2 < N;) {
		int num = table[p2] - table[p1];
		if (num >= M) {
			++p1;
			ans = min(ans, num);
		}
		else {
			++p2;
		}
	}
	cout << ans;
	return 0;
}