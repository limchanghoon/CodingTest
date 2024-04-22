#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Mold {
	int r, c, d;
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	const int dr[8] = { -2,-1,+1,+2,+2,+1,-1,-2 };
	const int dc[8] = { +1,+2,+2,+1,-1,-2,-2,-1 };

	int N, M, K, t;
	cin >> N >> M >> K >> t;
	queue<Mold> q;
	vector<vector<vector<int>>> table(2, vector<vector<int>>(N + 1, vector<int>(N + 1)));
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b;
		q.push({ a,b,0 });
	}

	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int d = q.front().d;
		q.pop();

		if (d == t) break;

		for (int i = 0; i < 8; ++i) {
			int nextR = r + dr[i];
			int nextC = c + dc[i];
			int nextD = d + 1;
			if (nextR <= 0 || nextR > N || nextC <= 0 || nextC > N) continue;
			if (table[nextD % 2][nextR][nextC] == 1) continue;
			table[nextD % 2][nextR][nextC] = 1;
			q.push({ nextR, nextC, nextD });
		}
	}

	bool check = false;
	for (int i = 0; i < K; ++i) {
		int r, c;
		cin >> r >> c;
		if (table[t % 2][r][c] == 1) check = true;
	}

	if (check) cout << "YES";
	else cout << "NO";
	return 0;
}
