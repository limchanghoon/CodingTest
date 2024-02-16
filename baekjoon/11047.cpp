#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int count = 0;
	int N, K;
	cin >> N >> K;
	vector<int> coins(N);
	for (int i = 0; i < N; ++i)
		cin >> coins[i];

	for (int i = N - 1; i >= 0; --i)
	{
		count += K / coins[i];
		K %= coins[i];
	}

	cout << count;
	
	return 0;
}