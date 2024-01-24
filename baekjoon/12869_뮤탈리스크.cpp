#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int scvs[61][61][61];
int attacks[6][3] = { {1,3,9}, {1,9,3} , {3,1,9} ,{3,9,1} ,{9,1,3} ,{9,3,1} };
int N;



int main()
{
	vector<int> firstHP(3);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> firstHP[i];

	for (int i = 0; i < 61; ++i)
		for (int j = 0; j < 61; ++j)
			for (int k = 0; k < 61; ++k)
				scvs[i][j][k] = INT32_MAX;

	scvs[firstHP[0]][firstHP[1]][firstHP[2]] = 0;
	queue<vector<int>> q;
	q.push(firstHP);
	while (!q.empty())
	{
		vector<int> curHP = q.front();
		q.pop();
		for (int i = 0; i < 6; ++i)
		{
			int hp0 = curHP[0] - attacks[i][0] < 0 ? 0 : curHP[0] - attacks[i][0];
			int hp1 = curHP[1] - attacks[i][1] < 0 ? 0 : curHP[1] - attacks[i][1];
			int hp2 = curHP[2] - attacks[i][2] < 0 ? 0 : curHP[2] - attacks[i][2];

			if (scvs[hp0][hp1][hp2] > scvs[curHP[0]][curHP[1]][curHP[2]] + 1)
			{
				scvs[hp0][hp1][hp2] = scvs[curHP[0]][curHP[1]][curHP[2]] + 1;
				q.push({ hp0,hp1,hp2 });
			}
		}
	}
	
	cout << scvs[0][0][0] << endl;

	return 0;
}