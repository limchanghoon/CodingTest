#include <iostream>

using namespace std;

int parent[1000001];

int getParent(int num) {
	if (parent[num] == num)
		return num;
	parent[num] = getParent(parent[num]);
	return parent[num];
}

void unionSet(int a, int b) {
	int aP = getParent(a);
	int bP = getParent(b);
	if (aP < bP)
		parent[aP] = bP;
	else
		parent[bP] = aP;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cout << "Scenario " << t << ":\n";
		int n, k, m;
		cin >> n >> k;

		// reset
		for (int i = 1; i <= n; ++i) {
			parent[i] = i;
		}

		for (int i = 0; i < k; ++i) {
			int a, b;
			cin >> a >> b;
			unionSet(a, b);
		}

		cin >> m;
		for (int i = 0; i < m; ++i) {
			int u, v;
			cin >> u >> v;
			if (getParent(u) == getParent(v))
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		cout << "\n";
	}
	return 0;
}