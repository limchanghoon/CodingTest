#include <iostream>
#include <algorithm>

using namespace std;

int T, N;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		cin >> N;
		int answer = -99999999;
		int sum = 0;
		for (int i = 0; i < N; ++i) {
			int a;
			cin >> a;
			if (sum > 0)	sum += a;
			else sum = a;
			answer = max(answer, sum);
		}
		cout << answer << "\n";
	}

	return 0;
}