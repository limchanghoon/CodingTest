#include <iostream>
#include <queue>

using namespace std;

int T, J, N;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> T;

	while (T--) {
		cin >> J >> N;
		int ans = 0;
		priority_queue<int> pq;
		for (int i = 0; i < N; ++i) {
			int R, C;
			cin >> R >> C;
			pq.push(R * C);
		}
		while (J > 0) {
			J -= pq.top();
			pq.pop();
			ans++;
		}
		cout << ans << "\n";
	}

	return 0;
}