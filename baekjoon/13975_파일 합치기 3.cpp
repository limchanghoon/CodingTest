#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	priority_queue<long long, vector<long long>, greater<long long>> pq;
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int K;
		long long ans = 0;
		cin >> K;
		for (int j = 0; j < K; ++j) {
			int temp;
			cin >> temp;
			pq.push(temp);
		}
		while (pq.size() > 1) {
			long long a = pq.top();
			pq.pop();
			long long b = pq.top();
			pq.pop();
			long long sum = a + b;
			ans += sum;
			pq.push(sum);
		}
		pq.pop();
		cout << ans << "\n";
	}

	return 0;
}