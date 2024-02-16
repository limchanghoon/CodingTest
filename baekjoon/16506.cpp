#include <iostream>
#include <string>

using namespace std;
const int ROW = 12;
const int COL = 6;
char table[ROW][COL];

int inner_isPuyo(int r, int c, char color)
{
	if (r < 0 || ROW <= r || c < 0 || COL <= c)
		return 0;

	int depth = 0;
	if (table[r][c] == color)
	{
		if (++depth >= 4)
			return depth;

		table[r][c] = '.';

		depth += inner_isPuyo(r + 1, c, color);
		depth += inner_isPuyo(r - 1, c, color);
		depth += inner_isPuyo(r, c + 1, color);
		depth += inner_isPuyo(r, c - 1, color);

		table[r][c] = color;
		return depth;
	}

	return 0;
}

bool isPuyo(int r, int c, char color)
{
	if (inner_isPuyo(r, c, color) >= 4)
		return true;

	return false;
}

void puyo(int r, int c, char color)
{
	if (r < 0 || ROW <= r || c < 0 || COL <= c)
		return;

	if (table[r][c] == color)
	{
		table[r][c] = '.';
		puyo(r + 1, c, color);
		puyo(r - 1, c, color);
		puyo(r, c + 1, color);
		puyo(r, c - 1, color);
	}
}

void gravity() 
{
	for (int i = COL - 1; i >= 0; --i)
	{
		int cnt = 0;
		for (int j = ROW - 1; j >= 0; --j)
		{
			if (table[j][i] == '.')
				++cnt;
			else if(cnt !=0)
			{
				table[j + cnt][i] = table[j][i];
				table[j][i] = '.';
			}
		}
	}
}

int main()
{
	int answer = 0;

	for (int i = 0; i < ROW; ++i)
	{
		string s;
		cin >> s;

		for (int j = 0; j < COL; ++j)
			table[i][j] = s[j];
	}

	bool nextLoop = false;
	do {
		nextLoop = false;
		for (int i = 0; i < ROW; ++i)
		{
			for (int j = 0; j < COL; ++j)
			{
				if (table[i][j] != '.' && isPuyo(i, j, table[i][j])) {
					puyo(i, j, table[i][j]);
					nextLoop = true;
				}
			}
		}
		gravity();

		if (nextLoop)
			++answer;
	} while (nextLoop);

	cout << answer << endl;
	return 0;
}

