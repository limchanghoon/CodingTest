#include <iostream>
#include <vector>
#include <queue>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int n, s, ans = 0;
	cin >> n;
	vector<int> A(n + 1);
	vector<int> check(n + 1);
	for (int i = 1; i <= n; ++i) 
		cin >> A[i];
	cin >> s;


	queue<int> q;
	q.push(s);
	check[s] = 1;
	ans++;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		int next = cur - A[cur];
		if (next > 0 && check[next] == 0) {
			q.push(next);
			check[next] = 1;
			ans++;
		}

		next = cur + A[cur];
		if (next <= n && check[next] == 0) {
			q.push(next);
			check[next] = 1;
			ans++;
		}
	}
	cout << ans;

	return 0;
}