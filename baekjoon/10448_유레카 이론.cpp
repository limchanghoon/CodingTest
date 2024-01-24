#include <iostream>
#include <vector>

using namespace std;

int solve(int K, vector<int>& Tn)
{
	for (int i = 0; i < Tn.size(); ++i) {
		for (int j = 0; j < Tn.size(); ++j) {
			for (int k = 0; k < Tn.size(); ++k) {
				if (Tn[i] + Tn[j] + Tn[k] == K)
					return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int T;
	cin >> T;
	vector<int> Tn;
	for (int i = 1; i <= 1000; ++i)
	{
		int temp = i * (i + 1) / 2;
		if (temp > 1000)
			break;
		Tn.push_back(temp);
	}

	for (int i = 0; i < T; ++i)
	{
		int K;
		cin >> K;
		cout << solve(K, Tn) << endl;
	}

	return 0;
}