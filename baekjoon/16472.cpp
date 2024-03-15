#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int N;
string str;
int counts_Alp[26];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> str;
	
	int ans = 0;
	int count = 0;
	int count_N = 0;
	for (int pre = 0, post = 0; post < str.length(); ++post) {
		++count;
		if (counts_Alp[str[post] - 'a'] > 0) {
			++counts_Alp[str[post] - 'a'];
			ans = max(ans, count);
		}
		else {
			++counts_Alp[str[post] - 'a'];
			if (++count_N <= N) {
				ans = max(ans, count);
				continue;
			}

			// 앞에서부터 제거
			while (true) {
				--count;
				if (--counts_Alp[str[pre] - 'a'] == 0) {
					--count_N;
					++pre;
					break;
				}
				++pre;
			}
		}
	}
	cout << ans;
	return 0;
}