#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	queue<pair<int,int>> q;
	int n, m, p1, p2;
	cin >> n >> p1 >> p2 >> m;
	bool visited[101] = { false, };
	vector<vector<int>> table(n + 1);
	while (m--) {
		int x, y;
		cin >> x >> y;
		table[x].push_back(y);
		table[y].push_back(x);
	}

	q.push({ p1,0 });
	visited[p1] = true;
	while (!q.empty()) {
		int cur = q.front().first, chon = q.front().second + 1;
		q.pop();

		for (int i = 0; i < table[cur].size(); ++i) {
			int next = table[cur][i];
			if (next == p2) {
				cout << chon;
				return 0;
			}

			if (!visited[next]) {
				q.push({ next,chon});
				visited[next] = true;
			}
		}
	}
	cout << -1;
	return 0;
}