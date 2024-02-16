#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct pos {
	int r, c, count;
	pos(int r, int c, int count) :r(r), c(c), count(count) {}
};

const int dr[4] = { +1,-1,+0,+0 };
const int dc[4] = { +0,+0,+1,-1 };

bool checkValid(int r, int c, vector<vector<char>>& table) {
	if (r < 0 || r >= table.size() || c < 0 || c >= table[0].size())
		return false;
	return true;
}

int solve(vector<vector<char>>& table) {
	queue<pos> q, q2;

	// 고슴도치 찾기
	for (int i = 0; i < table.size(); ++i)
		for (int j = 0; j < table[0].size(); ++j)
			if (table[i][j] == 'S') {
				q.push(pos(i, j, 0));
				i = table.size();
				break;
			}

	// 물 시작지 찾기
	for (int i = 0; i < table.size(); ++i)
		for (int j = 0; j < table[0].size(); ++j)
			if (table[i][j] == '*')
				q2.push(pos(i, j, 0));

	for (int t = 0; !q.empty(); ++t) {
		// 고슴도치 이동
		while (!q.empty() && q.front().count == t) {
			int r = q.front().r, c = q.front().c, count = q.front().count;
			q.pop();

			if (table[r][c] != 'S')//이동했지만 물이 덮침!
				continue;

			for (int i = 0; i < 4; ++i) {
				if (!checkValid(r + dr[i], c + dc[i], table))
					continue;
				char next = table[r + dr[i]][c + dc[i]];
				if (next == 'D')		// 비버
					return count + 1;
				if (next == '.') {
					table[r + dr[i]][c + dc[i]] = 'S';
					q.push(pos(r + dr[i], c + dc[i], count + 1));
				}
			}
		}

		// 물 이동
		while (!q2.empty() && q2.front().count == t) {
			int r = q2.front().r, c = q2.front().c, count = q2.front().count;
			q2.pop();
			for (int i = 0; i < 4; ++i) {
				if (!checkValid(r + dr[i], c + dc[i], table))
					continue;
				char next = table[r + dr[i]][c + dc[i]];
				if (next == '.' || next == 'S') {
					table[r + dr[i]][c + dc[i]] = '*';
					q2.push(pos(r + dr[i], c + dc[i], count + 1));
				}
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int R, C;
	cin >> R >> C;
	vector<vector<char>> table(R, vector<char>(C));
	for (int i = 0; i < R; ++i)
		for (int j = 0; j < C; ++j)
			cin >> table[i][j];

	int ans = solve(table);
	if (ans == -1)
		cout << "KAKTUS";
	else
		cout << ans;
	return 0;
}