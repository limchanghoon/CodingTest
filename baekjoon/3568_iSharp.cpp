#include <iostream>
#include <vector>

using namespace std;

bool isAlphabet(char c)
{
	if ('a' <= c && c <= 'z')
		return true;
	if ('A' <= c && c <= 'Z')
		return true;
	return
		false;
}

int main() {
	vector<string> table;
	string basic;
	string s;

	cin >> basic;
	

	do {
		cin >> s;
		table.push_back(s.substr(0, s.size() - 1));
	} while (getc(stdin) == ' ');
	

	for (int i = 0; i < table.size(); ++i) {
		cout << basic;
		int j = table[i].size() - 1;
		for (; j >= 0; --j)
		{
			if (isAlphabet(table[i][j]))
				break;
			if (table[i][j] == ']')
			{
				cout << table[i][j - 1] << table[i][j];
				--j;
			}
			else
				cout << table[i][j];
		}
		cout << " " << table[i].substr(0, j+1) << ";" << endl;
	}
	
}
