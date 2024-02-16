#include <iostream>
#include <string>

using namespace std;

int main()
{

	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); ++i)
	{
		char c = s[i];
		if ('a' <= c && c <= 'z')
			c = (c - 'a' + 13) % 26 + 'a';
		else if ('A' <= c && c <= 'Z')
			c = (c - 'A' + 13) % 26 + 'A';
		cout << c;
	}
	cout << endl;
	return 0;
}