#include <iostream>

using namespace std;

int solve(int N)
{
	for (int i = 1; i <= 1000000; ++i)
	{
		int cur = i;
		int sum = cur;
		while (cur != 0)
		{
			sum += cur % 10;
			cur /= 10;
		}

		if (N == sum)
			return i;
	}
	return 0;
}

int main()
{
	int N;
	cin >> N;

	cout << solve(N) << endl;
	return 0;
}