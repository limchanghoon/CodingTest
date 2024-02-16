#include <iostream>
#include <string>

using namespace std;

int main()
{
	int alp[26] = { 0, };
	string ans = "";
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string s;
		cin >> s;
		++alp[s[0] - 'a'];
	}

	for (int i = 0; i < 26; ++i)
		if (alp[i] >= 5)
			ans += 'a' + i;
	
	if (ans == "")
		ans = "PREDAJA";
	cout << ans << endl;

	return 0;
}