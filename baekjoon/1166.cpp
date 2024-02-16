#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, L, W, H;
	cin >> N >> L >> W >> H;

	double n = N;
	double top = 1000000000;
	double bottom = 0;
	double mid = (top + bottom) / 2;

	int T = 100;
	while (T--) {
		mid = (top + bottom) / 2;
		n = N;
		if (mid > L || mid > W || mid > H) {
			top = mid;
			continue;
		}

		n /= (long long)(L / mid);
		n /= (long long)(W / mid);
		n /= (long long)(H / mid);

		if (n <= 1) {
			bottom = mid;
		}
		else{
			top = mid;
		}
	}

	cout << fixed;
	cout.precision(10);
	cout << mid << endl;

	return 0;
}