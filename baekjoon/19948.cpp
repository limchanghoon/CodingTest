#include <iostream>
#include <string>

using namespace std;

int table[26];
int N;

bool solve(const string& str) {
	char pre = '-';
	for (int i = 0; i < str.size(); ++i) {
		if (pre == str[i]) continue;
		if (str[i] == ' ') {
			--N;
			if (N < 0) {
				cout << -1;
				return false;
			}
		}
		else if ('a' <= str[i] && str[i] <= 'z') {
			--table[str[i] - 'a'];
			if (table[str[i] - 'a'] < 0) {
				cout << -1;
				return false;
			}
		}
		else if ('A' <= str[i] && str[i] <= 'Z') {
			--table[str[i] - 'A'];
			if (table[str[i] - 'A'] < 0) {
				cout << -1;
				return false;
			}
		}
		pre = str[i];
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string str = "";
	string title = "";
	getline(cin, str);
	cin >> N;
	for (int i = 0; i < 26; ++i) {
		cin >> table[i];
	}

	// 시 제목 만들기
	bool check = true;
	for (int i = 0; i < str.size(); ++i) {
		if (check) {
			if ('a' <= str[i] && str[i] <= 'z')
				title += str[i] - 32;
			else if ('A' <= str[i] && str[i] <= 'Z')
				title += str[i];
			check = false;
		}
		if (str[i] == ' ') {
			check = true;
		}
	}
	

	if (solve(str) && solve(title)) {
		cout << title;
	}

	return 0;
}