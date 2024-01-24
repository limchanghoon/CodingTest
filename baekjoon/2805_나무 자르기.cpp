#include <iostream>
#include <vector>

using namespace std;

int solve(int N, int M)
{
	int ans = 0;
	vector<int> trees(N);
	for (int i = 0; i < N; ++i)
		cin >> trees[i];
	long long bottom = 0;
	long long top = 2000000000;
	int mid;

	while (bottom <= top)
	{
		mid = (bottom + top) / 2;
		long long sum = 0;
		for (int i = 0; i < N; ++i)
		{
			int temp = trees[i] - mid;
			if (temp > 0)
				sum += temp;
		}
		if (sum >= M) {
			ans = mid;
			bottom = static_cast<long long>(mid) + 1;
		}
		else if (sum < M) {
			top = static_cast<long long>(mid) - 1;
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	cout << solve(N, M);

	return 0;
}