#include <iostream>

using namespace std;

int gcd(int a, int b) {
	int r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	int ans1 = gcd(N, M);
	int ans2 = N * M / ans1;
	cout << ans1 << "\n" << ans2;
	return 0;
}