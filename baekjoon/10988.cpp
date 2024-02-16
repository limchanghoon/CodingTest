#include <iostream>
#include <string>

using namespace std;

int isPalindrome(string& S)
{
	for (int i = 0, j = S.size() - 1; i < S.size() / 2; ++i, --j)
		if (S[i] != S[j])
			return 0;
	return 1;
}

int main()
{
	string S;
	cin >> S;

	cout << isPalindrome(S) << endl;
	return 0;
}