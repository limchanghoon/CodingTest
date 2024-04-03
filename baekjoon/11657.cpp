#include <iostream>
#include <vector>

using namespace std;

const long long BIGVALUE = 333333333333;

struct Edge {
	int FROM, TO, COST;
};

long long ans[501];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	vector<Edge> table;
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; ++i) {
		int A, B, C;
		cin >> A >> B >> C;
		table.push_back({ A,B,C });
	}

	for (int i = 1; i <= N; ++i) ans[i] = BIGVALUE;

	ans[1] = 0;
	for (int i = 0; i < N - 1; ++i) {
		for (int j = 0; j < table.size(); ++j) {
			int FROM = table[j].FROM;
			int TO = table[j].TO;
			int COST = table[j].COST;
			if (ans[FROM] == BIGVALUE) continue;
			if (ans[TO] > ans[FROM] + COST) ans[TO] = ans[FROM] + COST;
		}
	}

	for (int i = 0; i < table.size(); ++i) {
		int FROM = table[i].FROM;
		int TO = table[i].TO;
		int COST = table[i].COST;
		if (ans[FROM] == BIGVALUE) continue;
		if (ans[TO] > ans[FROM] + COST) {
			cout << -1;
			return 0;
		}
	}

	for (int i = 2; i <= N; ++i) {
		if (ans[i] == BIGVALUE) cout << "-1\n";
		else cout << ans[i] << "\n";
	}

	return 0;
}