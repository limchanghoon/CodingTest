#include <iostream>
#include <string>
#include <stack>

using namespace std;

int T;

string solve(const string& str) {
	stack<char> stk;

	for (int i = 0; i < str.size(); ++i) {
		if (str[i] == '(') {
			stk.push('(');
		}
		else {
			if (stk.empty() || stk.top() == ')')
				return "NO";
			stk.pop();
		}
	}
	if (stk.empty())
		return "YES";
	else
		return "NO";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	string str;
	while (T--) {
		cin >> str;
		cout << solve(str) << "\n";
	}

	return 0;
}