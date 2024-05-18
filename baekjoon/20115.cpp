#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, maxIndex = 0;
	long long maxValue = 0;
	cin >> N;
	vector<long long> table(N);
	for (int i = 0; i < N; ++i) {
		cin >> table[i];
		if (maxValue < table[i]) {
			maxValue = table[i];
			maxIndex = i;
		}
	}

	long long temp = table[0];
	table[0] = table[maxIndex];
	table[maxIndex] = temp;

	double ans = table[0];
	for (int i = 1; i < N; ++i) {
		ans += (double)table[i] / 2;
	}

	cout << ans;

	return 0;
}