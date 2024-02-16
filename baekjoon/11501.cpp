#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int N;
		cin >> N;
		vector<int> table(N);
		for (int j = 0; j < N; ++j)
			cin >> table[j];

		long long curMax = table[N - 1];
		long long ans = 0;
		for (int j = N - 1; j >= 0; --j) {
			if (curMax < table[j])
				curMax = table[j];
			else if(curMax > table[j])
				ans += curMax - table[j];
		}
		cout << ans << "\n";
	}
	return 0;
}