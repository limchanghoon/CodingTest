#include <iostream>
#include <algorithm>

using namespace std;

int N;
int table[400];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		int S, E;
		cin >> S >> E;
		for (int j = S; j <= E; ++j) {
			++table[j];
		}
	}

	int ans = 0;
	int M = 0;
	int len = 0;
	for (int i = 1; i <= 365; ++i) {
		if (table[i] == 0) {
			ans += M * len;
			len = 0;
			M = 0;
		}
		else {
			M = max(M, table[i]);
			++len;
		}
	}
	ans += M * len;

	cout << ans;

	return 0;
}