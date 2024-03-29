#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int table[101];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	int ans = -99999999;
	int sum = 0;
	for (int i = 1; i < K; ++i) {
		cin >> table[i];
		sum += table[i];
	}
	for (int i = K; i <= N; ++i) {
		cin >> table[i];
		sum += table[i];
		sum -= table[i - K];
		ans = max(ans, sum);
	}
	cout << ans;

	return 0;
}