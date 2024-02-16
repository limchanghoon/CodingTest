#include <iostream>
#include <algorithm>

using namespace std;

int N;
int table[10][10];
int ans[2];
bool isPut[10][10];

int dr[2] = { -1,-1 };
int dc[2] = { +1,-1 };

bool isValid(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= N)
		return false;
	return true;
}

bool check(int r, int c) {
	for (int i = 0; i < 2; ++i) {
		int x = r + dr[i], y = c + dc[i];
		while (isValid(x, y)) {
			if (isPut[x][y])
				return false;
			x += dr[i];
			y += dc[i];
		}
	}
	return true;
}

void dfs(int r, int c, int count, int color) {
	if (r == N) {
		ans[color] = max(ans[color], count);
		return;
	}

	int nextR, nextC;
	if (color == 0) {
		if ((c == N - 1 || c == N - 2) && r % 2 == 0) {
			nextR = r + 1;
			nextC = 1;
		}
		else if ((c == N - 1 || c == N - 2) && r % 2 == 1) {
			nextR = r + 1;
			nextC = 0;
		}
		else {
			nextR = r;
			nextC = c + 2;
		}
	}
	else {
		if ((c == N - 1 || c == N - 2) && r % 2 == 0) {
			nextR = r + 1;
			nextC = 0;
		}
		else if ((c == N - 1 || c == N - 2) && r % 2 == 1) {
			nextR = r + 1;
			nextC = 1;
		}
		else {
			nextR = r;
			nextC = c + 2;
		}
	}


	if (table[r][c] == 1 && check(r, c)) {
		isPut[r][c] = true;
		dfs(nextR, nextC, count + 1, color);
	}

	isPut[r][c] = false;
	dfs(nextR, nextC, count, color);
}



int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> table[i][j];
		}
	}
	if (N == 1) {
		cout << table[0][0];
		return 0;
	}

	dfs(0, 0, 0, 0);
	dfs(0, 1, 0, 1);

	cout << ans[0] + ans[1] << endl;

	return 0;
}