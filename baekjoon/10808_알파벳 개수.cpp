#include <iostream>
#include <string>
using namespace std;

int main()
{
	string S;
	cin >> S;

	int results[26] = {0,};
	for (int i = 0; i < S.size(); ++i)
		++results[S[i] - 'a'];

	for (int i = 0; i < 26; ++i)
		cout << results[i] << " ";
	return 0;
}