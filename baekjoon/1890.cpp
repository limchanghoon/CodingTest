#include <iostream>
#include <vector>

using namespace std;


int main()
{
	int N;
	cin >> N;

	vector<vector<int>> table(N,vector<int>(N));
	vector<vector<long long>> results(N, vector<long long>(N));
	results[0][0] = 1;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> table[i][j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			long long jump = table[i][j];
			if (jump == 0)	continue;

			// 오른쪽
			if (j + jump < N)
			{
				results[i][j + jump] += results[i][j];
			}

			// 아래쪽
			if (i + jump < N)
			{
				results[i + jump][j] += results[i][j];
			}
		}
	}

	cout << results[N - 1][N - 1] << endl;

	return 0;
}