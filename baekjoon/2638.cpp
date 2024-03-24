#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct POS {
	int r, c;
};

const int dr[4] = { +1,-1,+0,+0 };
const int dc[4] = { +0,+0,+1,-1 };

int cnt = 0;
int N, M;
// -2 : ¹æ¹®ÇÑ ºóÄ­ , -1 : ºóÄ­
//  0 : Ä¡Áî, 1~4 : Á¢ÃË ¼ö
vector<vector<int>> table;
queue<POS> deleteQ;

bool isValid(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= M) return false;
	return true;
}

void dfs(int r, int c) {
	if (table[r][c] >= 0) {
		if (++table[r][c] == 2) {
			deleteQ.push({ r,c });
		}
		return;
	}
	if (table[r][c] == -2) return;
	table[r][c] = -2;

	for (int i = 0; i < 4; ++i) {
		int nextR = dr[i] + r;
		int nextC = dc[i] + c;
		if (isValid(nextR, nextC)) dfs(nextR, nextC);
	}
}

void deleteCheese() {
	int sz = deleteQ.size();
	while (sz--) {
		POS nextPos = deleteQ.front();
		deleteQ.pop();
		table[nextPos.r][nextPos.c] = -1;
		dfs(nextPos.r, nextPos.c);
		--cnt;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	table.resize(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> table[i][j];
			if (table[i][j] == 1) {
				table[i][j] = 0;
				++cnt;
			}
			else {
				table[i][j] = -1;
			}
		}
	}

	// Ä¡Áî°¡ ¾øÀ¸¸é
	if (cnt == 0) {
		cout << 0;
		return 0;
	}

	// Ä¡Áî Á¦°Å
	dfs(0, 0);
	for (int i = 1; true; ++i) {
		deleteCheese();
		if (cnt == 0) {
			cout << i;
			return 0;
		}
	}

	return 0;
}