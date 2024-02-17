#include <iostream>
#include <algorithm>

using namespace std;

int d, n, m;
int table[50002];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int answer = 0;
	cin >> d >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> table[i];
	}
	table[n] = 0;
	table[n + 1] = d;
	sort(table, table + n + 2);

	int left = 1;
	int right = 1000000000;
	int mid = (left + right) / 2;

	while (left <= right) {
		int cnt = 0;
		mid = (left + right) / 2;

		int start = 0;
		for (int i = 1; i < n + 2; ++i) {
			if (table[i] - table[start] >= mid)
				start = i;
			else
				cnt++;
		}

		if (cnt <= m) {
			answer = max(answer, mid);
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << answer;

	return 0;
}
