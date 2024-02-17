#include <iostream>

using namespace std;

int N, T;
int L[1000];
int R[1000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int answer = 1000001;

	cin >> N >> T;
	int sumMin = 0;
	int sumMax = 0;
	for (int i = 0; i < N; ++i) {
		cin >> L[i] >> R[i];
		sumMin += L[i];
		sumMax += R[i];
	}

	if (T < sumMin || T > sumMax) {
		cout << -1;
		return 0;
	}


	// 이분탑색
	int top = 1000000;
	int bottom = 1;
	int mid = (top + bottom) / 2;
	while (bottom <= top) {
		mid = (top + bottom) / 2;

		int mx = 0;
		for (int i = 0; i < N; ++i) {
			if (L[i] > mid) {
				mx = T - 1;
				break;
			}
			mx += R[i] > mid ? mid : R[i];
		}

		if (T <= mx) {
			answer = mid;
			top = mid - 1;
		}
		else {
			bottom = mid + 1;
		}
	}
	cout << answer;

	return 0;
}
