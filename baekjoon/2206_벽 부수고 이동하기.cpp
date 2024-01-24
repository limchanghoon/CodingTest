#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

struct pos {
	int r, c, count;
	bool destruction;
	pos(int r, int c, int count, bool destruction) :r(r), c(c), count(count), destruction(destruction) {}
};

const int dr[4] = { +1,-1,+0,+0 };
const int dc[4] = { +0,+0,+1,-1 };

int solve(int N, int M, vector<vector<int>>& table) {
	queue<pos> q;
	deque<deque<bool>> visited0(N, deque<bool>(M));
	deque<deque<bool>> visited1(N, deque<bool>(M));
	q.push(pos(0, 0, 1, false));
	visited0[0][0] = true;
	visited1[0][0] = true;
	while (!q.empty()) {
		int r = q.front().r, c = q.front().c, count = q.front().count;
		bool destruction = q.front().destruction;
		q.pop();

		if (r == N - 1 && c == M - 1)			// ¸ñÀûÁö µµÂøÇÔ
			return count;

		for (int i = 0; i < 4; ++i) {
			int nextR = r + dr[i], nextC = c + dc[i];
			if (nextR < 0 || nextR >= N || nextC < 0 || nextC >= M)	// ¹üÀ§ Ã¼Å©
				continue;

			if (table[nextR][nextC] + destruction == 0 && !visited0[nextR][nextC]) {		//ÆÄ±« 0
				visited0[nextR][nextC] = true;
				q.push(pos(nextR, nextC, count + 1, false));
			}
			else if(table[nextR][nextC] + destruction == 1 && !visited1[nextR][nextC]) {	// ÆÄ±« 1
				visited1[nextR][nextC] = true;
				q.push(pos(nextR, nextC, count + 1, true));
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<vector<int>> table(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		string temp;
		cin >> temp;
		for (int j = 0; j < M; ++j)
			table[i][j] = temp[j] - '0';
	}
	cout << solve(N, M, table);

	return 0;
}