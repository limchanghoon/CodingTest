#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int table[5000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int answer = 9999999;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> table[i];
	}

	int left = 0, right = 9999, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		int count = 1;
		int low = 99999, high = -1;
		for (int i = 0; i < N; ++i) {
			low = min(low, table[i]);
			high = max(high, table[i]);
			if (high - low > mid) {
				low = table[i], high = table[i];
				++count;
			}
		}

		if (count <= M) {
			answer = min(answer, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << answer;

	return 0;
}