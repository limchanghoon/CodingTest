#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int dx[] = { +1,-1,+0,+0 };
const int dy[] = { +0,+0,+1,-1 };

int innerDFS(int x, int y, vector<vector<int>>& table)
{
	if (x < 0 || x >= table.size() || y < 0 || y >= table[0].size())	// 범위 체크
		return 0;
	if (table[x][y] != 0)		// 0이면 가능 지역, 1이면 불가능 지역, -1이면 방문 지역
		return 0;
	table[x][y] = -1;

	int count = 1;
	for (int i = 0; i < 4; ++i)
		count += innerDFS(x + dx[i], y + dy[i], table);
	return count;
}

void DFS(vector<vector<int>>& table)
{
	vector<int> areas;
	for (int x = 0; x < table.size(); ++x)
		for (int y = 0; y < table[0].size(); ++y) {
			int temp = innerDFS(x, y, table);
			if (temp != 0)
				areas.push_back(temp);
		}

	sort(areas.begin(), areas.end());
	cout << areas.size() << "\n";
	for (int i = 0; i < areas.size(); ++i)
		cout << areas[i] << " ";
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int M, N, K;
	cin >> M >> N >> K;
	vector<vector<int>> table(N, vector<int>(M));  // x,y 순으로 정했음
	for (int i = 0; i < K; ++i)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int x = x1; x < x2; ++x)
			for (int y = y1; y < y2; ++y)
				table[x][y] = 1;
	}

	DFS(table);
	return 0;
}