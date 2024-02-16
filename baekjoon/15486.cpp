#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<pair<int, int>> table(N, make_pair(0, 0));

	for (int i = 0; i < N; ++i)
		cin >> table[i].first >> table[i].second;

	int curMax = 0;
	vector<int> results(N+1);

	for (int i = 0; i < N; ++i)
	{
		if (results[i] < curMax)
			results[i] = curMax;

		curMax = max(curMax, results[i]);

		int idx = i + table[i].first;
		if (idx <= N) {
			int temp = results[i] + table[i].second;
			results[idx] = max(results[idx], temp);
		}
	}

	cout << max(curMax, results[N]) << endl;

	return 0;
}