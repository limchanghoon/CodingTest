#include <iostream>
#include <vector>

using namespace std;

int search(int N, int M, vector<int>& moneys)
{
	//1000000000 (10¾ï)
	int pre = 0, post = 1000000000;
	int mid;
	while (true)
	{
		mid = (pre + post) / 2;
		bool isOk = true;
		int money = mid;
		int count = 1;
		for (int i = 0; i < N; ++i)
		{
			if (money < moneys[i])
			{
				money = mid;
				++count;
			}

			money -= moneys[i];
			if (money < 0 || count >M)
			{
				isOk = false;
				break;
			}
		}
		if (isOk)
		{
			if (pre == mid)
				return pre;
			post = mid;
		}
		else
		{
			if (pre == mid)
				return post;
			pre = mid;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<int> moneys(N);
	for (int i = 0; i < N; ++i)
		cin >> moneys[i];
	cout << search(N, M, moneys);
	return 0;
}