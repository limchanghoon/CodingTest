#include <iostream>
#include <string>

using namespace std;

int search(const string& N)
{
	int curPos = 0, curNum = 0;
	while (true)
	{
		string num = to_string(++curNum);
		for (int i = 0; i < num.size(); ++i)
			if (N[curPos] == num[i])
				if (++curPos == N.size())
					return curNum;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
	string N;
	cin >> N;
	cout << search(N);

	return 0;
}