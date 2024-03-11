#include <iostream>
#include <algorithm>

#define BIGVALUE 2100000000

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int answer = BIGVALUE;
	long long X, Y;
	cin >> X >> Y;
	long long pre = Y * 100 / X;
	int left = 1, right = 1000000000, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		long long _X = X + mid;
		long long _Y = Y + mid;
		long long cur = _Y * 100 / _X;
		if (pre < cur) {
			answer = min(answer, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	if (answer == BIGVALUE) cout << -1;
	else cout << answer;
}