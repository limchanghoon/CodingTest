#include <iostream>
#include <vector>
#include <string>
using namespace std;

void swap(char& a, char& b)
{
	char temp = a;
	a = b;
	b = temp;
}

int calculate(const vector<string>& strs)
{
	int result = 0;
	int N = strs.size();

	// 가로
	for (int i = 0; i < N; ++i)
	{
		int cnt = 1;
		for (int j = 0; j < N - 1; ++j)
		{
			if (strs[i][j] == strs[i][j + 1])
				result = max(result, ++cnt);
			else
				cnt = 1;
		}
	}

	// 세로
	for (int i = 0; i < N; ++i)
	{
		int cnt = 1;
		for (int j = 0; j < N - 1; ++j)
		{
			if (strs[j][i] == strs[j + 1][i])
				result = max(result, ++cnt);
			else
				cnt = 1;
		}
	}


	return result;
}

int main() {
	int answer = 0;
	int N;
	vector<string> strs;
	cin >> N;


	for (int i = 0; i < N; ++i)
	{
		string s;
		cin >> s;
		strs.push_back(s);
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (i + 1 < N && strs[i][j] != strs[i + 1][j]) {
				swap(strs[i][j], strs[i + 1][j]);
				answer = max(answer, calculate(strs));
				swap(strs[i][j], strs[i + 1][j]);
			}

			if (j + 1 < N && strs[i][j] != strs[i][j + 1]) {
				swap(strs[i][j], strs[i][j + 1]);
				answer = max(answer, calculate(strs));
				swap(strs[i][j], strs[i][j + 1]);
			}
		}
	}

	cout << answer << endl;
	return 0;
}