#include <iostream>
#include <vector>

using namespace std;

#define TOP 2
#define BOTTOM 5

int N, M, x, y, K;

int dx[4] = { +0,+0,-1,+1 };
int dy[4] = { +1,-1,+0,+0 };

// x0x
// 123
// x4x
// x5x
int dice[6];

bool moveTo(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= M)
		return false;
	x = r;
	y = c;
	return true;
}

// 동쪽은 1, 서쪽은 2, 북쪽은 3, 남쪽은 4
void moveDice(int T) {
	int temp;

	switch (T)
	{
	case 1:
		temp = dice[5];
		dice[5] = dice[3];
		dice[3] = dice[2];
		dice[2] = dice[1];
		dice[1] = temp;
		return;
	case 2:
		temp = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[3];
		dice[3] = dice[5];
		dice[5] = temp;
		return;
	case 3:
		temp = dice[0];
		dice[0] = dice[2];
		dice[2] = dice[4];
		dice[4] = dice[5];
		dice[5] = temp;
		return;
	case 4:
		temp = dice[5];
		dice[5] = dice[4];
		dice[4] = dice[2];
		dice[2] = dice[0];
		dice[0] = temp;
		return;
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> x >> y >> K;
	vector<vector<int>> table(N, vector<int>(M));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> table[i][j];
		}
	}

	while (K--) {
		int T;
		cin >> T;

		if (!moveTo(x + dx[T - 1], y + dy[T - 1]))
			continue;

		moveDice(T);

		if (table[x][y] == 0) {
			table[x][y] = dice[BOTTOM];
		}
		else {
			dice[BOTTOM] = table[x][y];
			table[x][y] = 0;
		}

		cout << dice[TOP] << "\n";
	}

	return 0;
}