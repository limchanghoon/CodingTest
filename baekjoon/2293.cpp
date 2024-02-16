#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	vector<int> table(k + 1);
	table[0] = 1;

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
			table[j] += table[j - coins[i]];
		}
	}

	cout << table[k] << endl;


	return 0;
}