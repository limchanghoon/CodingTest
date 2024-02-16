#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int moveR[] = { -1,0,1,0 };
const int moveC[] = { 0,1,0,-1 };
bool visited[20][20][20][20];

int N, M;
vector<int> coins;
vector<string> table;

struct INFO { int r1, c1, r2, c2, depth; };

bool isOut(int r, int c)
{
	if (0 > r || r >= N || 0 > c || c >= M)
		return true;
	return false;
}


int BFS()
{
	int depth = 0;

	queue<INFO> q;
	q.push({ coins[0], coins[1], coins[2], coins[3], 0 });
	while (!q.empty())
	{
		int r1 = q.front().r1;
		int c1 = q.front().c1;
		int r2 = q.front().r2;
		int c2 = q.front().c2;
		depth = q.front().depth;
		visited[r1][c1][r2][c2] = true;
		q.pop();

		if (depth >= 10) {
			depth = -1;
			break;
		}

		for (int i = 0; i < 4; ++i) {
			int rr1 = r1 + moveR[i];
			int cc1 = c1 + moveC[i];
			int rr2 = r2 + moveR[i];
			int cc2 = c2 + moveC[i];

			if (0 <= rr1 && rr1 < N && 0 <= cc1 && cc1 < M && 0 <= rr2 && rr2 < N && 0 <= cc2 && cc2 < M)	// µÎ°³ ´Ù ÇÊµå ¾È¿¡ À§Ä¡ÇÔ
			{
				if (table[rr1][cc1] == '#' && table[rr2][cc2] == '#')
					continue;

				if (table[rr1][cc1] == '#')
					rr1 = r1, cc1 = c1;

				if (table[rr2][cc2] == '#')
					rr2 = r2, cc2 = c2;

				if (!visited[rr1][cc1][rr2][cc2]) {
					q.push({ rr1, cc1, rr2, cc2, depth + 1 });
					visited[rr1][cc1][rr2][cc2] = true;
				}
			}
			else if (isOut(rr1, cc1) && isOut(rr2, cc2))	// µ¿Àü µÎ°³ ´Ù ¶³¾îÁü
				continue;
			else if (isOut(rr1, cc1))	// µ¿Àü1 ¶³¾îÁü
				return depth + 1;
			else if (isOut(rr2, cc2))	// µ¿Àü2 ¶³¾îÁü
				return depth + 1;
		}
	}
	return -1;
}

int main()
{
	cin >> N >> M;
	table.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> table[i];

		for (int j = 0; j < M; ++j)
		{
			if (table[i][j] == 'o') {
				coins.push_back(i);
				coins.push_back(j);
				table[i][j] = '.';
			}
		}
	}
	cout << BFS() << endl;

	return 0;
}