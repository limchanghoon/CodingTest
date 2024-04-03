#include <iostream>
#include <algorithm>

using namespace std;

int N;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cout << fixed;
	cout.precision(3);
	cin >> N;
	double num = 1, ans = 0;
	for (int i = 0; i < N; ++i) {
		double temp;
		cin >> temp;
		num *= temp;
		ans = max(ans, num);
		if (num < 1) num = 1;
	}

	cout << ans;

	return 0;
}