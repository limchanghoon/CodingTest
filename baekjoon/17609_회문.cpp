#include <iostream>
#include <string>

using namespace std;


bool checkPalindrome(const string& str) {
	int size = str.size();
	for (int i = 0; i < size / 2; ++i) {
		if (str[i] != str[size - 1 - i])
			return false;
	}
	return true;
}

int solve(const string& str) {
	int size = str.size();
	int count = 0;
	for (int i = 0; i < size/2; ++i) {
		if (str[i] != str[size - 1 - i]) {
			if (checkPalindrome(str.substr(i, size - 1 - 2 * i)) || checkPalindrome(str.substr(i + 1, size - 1 - 2 * i)))
				return 1;
			else
				return 2;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		string str;
		cin >> str;
		cout << solve(str) << "\n";
	}
	return 0;
}