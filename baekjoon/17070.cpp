#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> vec;
int N;
int answer = 0;

bool check(int r, int c)
{
	if (r < N && c < N && vec[r][c] == 0)
		return true;

	return false;
}

void DFS(int r1, int c1, int r2, int c2)
{
	if (r2 == N - 1 && c2 == N - 1) {
		++answer;
		return;
	}

	if (r1 == r2 && c1 + 1 == c2) // 가로
	{
		if (check(r2, c2 + 1))
			DFS(r2, c2, r2, c2 + 1);
		if (check(r2, c2 + 1) && check(r2 + 1, c2 + 1) && check(r2 + 1, c2))
			DFS(r2, c2, r2 + 1, c2 + 1);
	}
	else if (r1 + 1 == r2 && c1 == c2) // 세로
	{
		if (check(r2 + 1, c2))
			DFS(r2, c2, r2 + 1, c2);
		if (check(r2, c2 + 1) && check(r2 + 1, c2 + 1) && check(r2 + 1, c2))
			DFS(r2, c2, r2 + 1, c2 + 1);

	}
	else if (r1 + 1 == r2 && c1 + 1 == c2) // 대각선
	{
		if (check(r2, c2 + 1))
			DFS(r2, c2, r2, c2 + 1);
		if (check(r2 + 1, c2))
			DFS(r2, c2, r2 + 1, c2);
		if (check(r2, c2 + 1) && check(r2 + 1, c2 + 1) && check(r2 + 1, c2))
			DFS(r2, c2, r2 + 1, c2 + 1);
	}
}


int main()
{
	cin >> N;

	vec.assign(N, vector<int>(N));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> vec[i][j];
		}
	}

	DFS(0, 0, 0, 1);

	cout << answer << endl;

	return 0;
}