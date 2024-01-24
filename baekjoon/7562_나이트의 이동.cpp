#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int xArray[8] = { +1,+1,+2,+2,-1,-1,-2,-2 };
const int yArray[8] = { +2,-2,+1,-1,+2,-2,+1,-1 };

int solve(int I, int x, int y, int u, int v)
{
	vector<vector<int>> table(I, vector<int>(I, numeric_limits<int>::max()));
	queue<pair<int,int>> q;
	table[x][y] = 0;
	q.push({ x,y });
	while (!q.empty())
	{
		int curX = q.front().first, curY = q.front().second;
		q.pop();
		if (curX == u && curY == v)	// 목적지 도착함(목적지에서 더 이동할 필요 없음)
			return table[u][v];

		int newCost = table[curX][curY] + 1;
		for (int i = 0; i < 8; ++i) {
			int newX = curX + xArray[i];
			int newY = curY + yArray[i];
			if (newX < 0 || newX >= I || newY < 0 || newY >= I) // 보드판 벗어남
				continue;
			if (table[newX][newY] == numeric_limits<int>::max()) // 아직 방문 안함
			{
				table[newX][newY] = newCost;
				q.push({ newX, newY});
			}
		}
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int I, x, y, u, v;
		cin >> I >> x >> y >> u >> v;
		cout << solve(I, x, y, u, v) << "\n";
	}
	return 0;
}