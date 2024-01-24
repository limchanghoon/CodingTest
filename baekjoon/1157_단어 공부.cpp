#include <iostream>
#include <string>

using namespace std;

char solve(string& s)
{
	char result = '?';
	int maxValue = 0;
	int results[26] = { 0, };
	for (int i = 0; i < s.size(); ++i)
	{
		char chr = s[i];
		if ('a' <= chr && chr <= 'z')
			++results[chr - 'a'];
		else if ('A' <= chr && chr <= 'Z')
			++results[chr - 'A'];
	}

	for (int i = 0; i < 26; ++i)
		if (maxValue == results[i]) {
			result = '?';
		}
		else if(maxValue < results[i]) {
			maxValue = results[i];
			result = 'A' + i;
		}
	

	return result;
}

int main()
{
	string s;
	cin >> s;

	cout << solve(s) << endl;

	return 0;
}