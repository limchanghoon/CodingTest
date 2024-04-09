#include <iostream>

using namespace std;

bool table[2000001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	long long ans = 0;
	int N, x;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;
		table[temp] = true;
	}
	cin >> x;

	for (int i = 1; i <= x / 2; ++i) {
		if (i == x - i) continue;
		if (table[i] && table[x - i]) ++ans;
	}
	cout << ans;

	return 0;
}