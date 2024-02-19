#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int answer = 100;
int N, M;
int rr, rc;
int br, bc;
int holeR, holeC;
string table[10];

int dp[10][10][10][10];

int dr[4] = { +1,-1,+0,+0 };
int dc[4] = { +0,+0,+1,-1 };

bool checkValid(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= M)
		return false;
	return true;
}

int moveBall(int& r, int& c, int T) {
	int len = 0;
	while (true) {
		if (table[r + dr[T]][c + dc[T]] == '.') {
			r += dr[T];
			c += dc[T];
			++len;
			continue;
		}
		else if (table[r + dr[T]][c + dc[T]] == 'O') {
			r += dr[T];
			c += dc[T];
			++len;
			break;
		}
		else {
			break;
		}
	}
	return len;
}

void dfs(int depth) {
	if (depth >= 11)
		return;
	int curRR = rr;
	int curRC = rc;
	int curBR = br;
	int curBC = bc;

	for (int i = 0; i < 4; ++i) {
		rr = curRR;
		rc = curRC;
		br = curBR;
		bc = curBC;
		int lenR = moveBall(rr, rc, i);
		int lenB = moveBall(br, bc, i);

		// 둘다 골인
		if (rr == holeR && rc == holeC && br == holeR && bc == holeC) {
			continue;
		}

		// 겹친 거 체크
		if (rr == br && rc == bc) {
			if (lenR > lenB) {
				rr -= dr[i];
				rc -= dc[i];
			}
			else {
				br -= dr[i];
				bc -= dc[i];
			}
		}

		// 경우의 수 줄이기
		if (dp[rr][rc][br][bc] <= depth)
			continue;
		dp[rr][rc][br][bc] = depth;

		if (br == holeR && bc == holeC) {
			continue;
		}
		else if (rr == holeR && rc == holeC) {
			answer = min(answer, depth);
			continue;
		}
		else {
			dfs(depth + 1);
			continue;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> table[i];
		for (int j = 0; j < M; ++j) {
			if (table[i][j] == 'R') {
				rr = i;
				rc = j;
				table[i][j] = '.';
			}
			else if (table[i][j] == 'B') {
				br = i;
				bc = j;
				table[i][j] = '.';
			}
			else if (table[i][j] == 'O') {
				holeR = i;
				holeC = j;
			}
		}
	}
	memset(dp, 100, sizeof(dp));
	dfs(1);
	if (answer == 100)
		cout << -1;
	else
		cout << answer;
	return 0;
}