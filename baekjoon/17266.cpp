#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int table[100000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int cur = 0;
	int answer = 99999999;
	cin >> N >> M;
	for (int i = 0; i < M; ++i) {
		cin >> table[i];
	}

	int left = 1, right = 100000, mid;

	while (left <= right) {
		mid = (left + right) / 2;
		bool check = false;
		int pos = 0;
		for (int i = 0; i < M; ++i) {
			int forward = table[i] - mid;
			int back = table[i] + mid;

			if (pos < forward) {
				check = true;
				break;
			}
			pos = back;
		}
		if (pos < N)
			check = true;

		if (check) {
			left = mid + 1;
		}
		else {
			answer = min(answer, mid);
			right = mid - 1;
		}
	}

	cout << answer;

	return 0;
}