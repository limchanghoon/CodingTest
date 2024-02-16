#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N, X;
	long long maxValue=0, sum=0, count=0;
	vector<int> table;
	cin >> N >> X;
	for (int i = 0; i < N; ++i) {
		int a;
		cin >> a;
		table.push_back(a);
		if (i < X)
			sum += a;
	}

	if (sum != 0) {
		maxValue = sum;
		++count;
	}

	for (int i = X, j =0; i < N; ++i, ++j)
	{
		sum = sum - table[j] + table[i];
		if (sum > maxValue)
		{
			maxValue = sum;
			count = 1;
		}
		else if (sum == maxValue)
			++count;
	}
	if(maxValue == 0)
		cout << "SAD" << endl;
	else
		cout << maxValue << endl << count << endl;

	return 0;
}