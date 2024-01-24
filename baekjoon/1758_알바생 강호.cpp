#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	long long result = 0;
	cin >> N;
	vector<int> tips;
	for (int i = 0; i < N; ++i)
	{
		int tip;
		cin >> tip;
		tips.push_back(tip);
	}
	sort(tips.begin(), tips.end(), greater<int>());
	for (int i = 0; i < N; ++i)
	{
		int temp = tips[i];
		temp -= i;
		if (temp <= 0)
			break;
		result += temp;
	}

	cout << result;
	return 0;
}