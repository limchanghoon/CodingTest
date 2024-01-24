#include <iostream>
#include <vector>

using namespace std;

const int dy[] = { +1,-1,+0,+0 };
const int dx[] = { +0,+0,+1,-1 };

inline int max(int a, int b) { return a > b ? a : b; }

int innerDFS(int r, int c, vector<vector<int>>& foods)
{
	if (r < 0 || r >= foods.size() || c < 0 || c >= foods[0].size())	// 범위 벗어남
		return 0;
	if (foods[r][c] != 1)		// 방문했거나 음식이 없음
		return 0;
	foods[r][c] = -1;	// 방문처리

	int count = 1;
	for (int i = 0; i < 4; ++i)
		count += innerDFS(r + dy[i], c + dx[i], foods);
	return count;
}

int DFS(vector<vector<int>>& foods)
{
	int ans = 0;
	for (int i = 0; i < foods.size(); ++i)
		for (int j = 0; j < foods[0].size(); ++j)
			ans = max(ans, innerDFS(i, j, foods));
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M, K;
	cin >> N >> M >> K;
	vector<vector<int>> foods(N,vector<int>(M));
	for (int i = 0; i < K; ++i)
	{
		int r, c;
		cin >> r >> c;
		foods[r - 1][c - 1] = 1;
	}

	cout << DFS(foods);

	return 0;
}