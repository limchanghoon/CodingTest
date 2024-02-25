#include <iostream>
#include <algorithm>

using namespace std;

int M;

int getCount(int num) {
	int cnt = 0;
	for (int i = 5; i <= num; i *= 5) {
		cnt += num / i;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> M;
	int answer = 999999999, left = 5, right = 500000000, mid;

	while (left <= right) {
		mid = (left + right) / 2;
		int cnt = getCount(mid);
		if (cnt < M)	left = mid + 1;
		else if (cnt > M)	right = mid - 1;
		else {
			right = mid - 1;
			answer = min(answer, mid);
		}
	}
	if (answer == 999999999)	cout << -1;
	else	cout << answer;

	return 0;
}