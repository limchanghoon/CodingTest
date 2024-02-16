/*
//¿ÏÀüÅ½»ö//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 0;

void innerDFS(int cur, int curHP, int curHappiness, vector<vector<int>>& table)
{
	if (curHP > 0)
		ans = max(ans, curHappiness);
	else
		return;

	for (int i = cur; i < table.size(); ++i)
		innerDFS(i + 1, curHP - table[i][0], curHappiness + table[i][1], table);
}

void DFS(vector<vector<int>>& table)
{
	innerDFS(0, 100, 0, table);
}

int main()
{
	int N;
	cin >> N;
	vector<vector<int>> table(N, vector<int>(2));
	for (int i = 0; i < N; ++i)
		cin >> table[i][0];
	for (int i = 0; i < N; ++i)
		cin >> table[i][1];
	DFS(table);
	cout << ans;
	return 0;
}
*/

//DP
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int DP[101] = { 0, };
	int N;
	cin >> N;
	vector<int> cost(N);
	vector<int> happiness(N);
	for (int i = 0; i < N; ++i)
		cin >> cost[i];
	for (int i = 0; i < N; ++i)
		cin >> happiness[i];

	for (int i = 0; i < N; i++)
		for (int j = 100; j > cost[i]; j--)
			DP[j] = max(DP[j], DP[j - cost[i]] + happiness[i]);

	cout << DP[100];
	return 0;
}