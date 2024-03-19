#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct MyStruct {
	int x, y, count;
};

int N, C, M;
vector<MyStruct> table;
vector<int> sums;

bool CMP(const MyStruct& a, const MyStruct& b) {
	if (a.y == b.y) {
		return a.x < b.x;
	}
	else {
		return a.y < b.y;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int ans = 0;

	cin >> N >> C >> M;
	table.resize(M);
	sums.resize(N + 1);
	for (int i = 0; i < M; ++i) {
		cin >> table[i].x >> table[i].y >> table[i].count;
	}

	sort(table.begin(), table.end(), CMP);

	for (int i = 0; i < M; ++i) {
		int from = table[i].x;
		int to = table[i].y;
		int cnt = table[i].count;

		int minV = 2000000002;
		for (int j = from; j < to; ++j) {
			minV = min(minV, C - sums[j]);
		}
		minV = min(minV, cnt);
		for (int j = from; j < to; ++j) {
			sums[j] += minV;
		}
		ans += minV;
	}
	cout << ans;

	return 0;
}