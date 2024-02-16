#include <iostream>
#include <algorithm>

using namespace std;

string solve(int N)
{
	int table[1001] = { 0,1,0,1, };
	for (int i = 4; i <= N; ++i)
	{
		if (min(table[i - 1], table[i - 3]) == 0)
			table[i] = 1;
		else
			table[i] = 0;
	}

	if (table[N] == 1)
		return "SK";
	else
		return "CY";
}

int main()
{
	int N;
	cin >> N;
	cout << solve(N) << endl;
	return 0;
}