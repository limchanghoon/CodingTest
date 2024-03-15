#include <iostream>
#include <algorithm>

using namespace std;

int L, n;
int table[50];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> L;
	for (int i = 0; i < L; ++i) {
		cin >> table[i];
	}
	cin >> n;

	sort(table, table + L);

	int left = 0, right = 99999;
	for (int i = 0; i < L; ++i) {
		if (n == table[i]) {
			cout << 0;
			return 0;
		}
		else if (n > table[i]) {
			left = max(left, table[i]);
		}
		else if (n < table[i]) {
			right = min(right, table[i]);
		}
	}

	int ans = 0;
	for (int i = left + 1; i < n; ++i) {
		ans += (right - n);
	}
	ans += right - n - 1;
	cout << ans;

	return 0;
}