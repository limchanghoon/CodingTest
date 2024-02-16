#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int BIG = 10000000;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> table(k + 1, BIG);
	table[0] = 0;

	vector<int> coins;
	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		coins.push_back(t);
	}
	sort(coins.begin(), coins.end());


	for (int i = 0; i < coins.size(); ++i)
	{
		for (int j = coins[i]; j <= k; ++j)
		{
			table[j] = min(table[j], table[j - coins[i]] + 1);
		}
	}
	if (table[k] == BIG)
		table[k] = -1;

	cout << table[k] << endl;


	return 0;
}