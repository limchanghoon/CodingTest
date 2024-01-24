#include <iostream>
#include <string>

using namespace std;

string solve(string& name) {
	string ans = "";
	int N = name.size();
	int alp[26] = { 0, };
	for (int i = 0; i < N; ++i)
		++alp[name[i] - 'A'];

	for (int i = 0; i < N / 2; ++i) {
		bool check = false;
		for (int j = 0; j < 26; ++j) {
			if (alp[j] >= 2) {
				check = true;
				alp[j] -= 2;
				ans += j + 'A';
				break;
			}
		}
		if (!check)
			return "I'm Sorry Hansoo";
	}

	// 홀수면 가운데 하나 넣어줘여함
	if (N % 2 == 1) {
		for (int j = 0; j < 26; ++j) {
			if (alp[j] == 1) {
				alp[j] -= 1;
				ans += j + 'A';
				break;
			}
		}
	}

	for (int i = N / 2 - 1; i >= 0; --i)
		ans += ans[i];
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string name;
	cin >> name;
	cout << solve(name);

	return 0;
}