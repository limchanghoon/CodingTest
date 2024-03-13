#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int T;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	while (T--) {
		string a, b, ans = "";
		cin >> a >> b;
		// 뒤집기
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		// 길이 맞춤
		int maxSize = max(a.size(), b.size());
		a.resize(maxSize, '0');
		b.resize(maxSize, '0');

		// 더하기 실행
		int count = 0;
		for (int i = 0; i < maxSize; ++i) {
			if (a[i] == '1') ++count;
			if (b[i] == '1') ++count;

			if (count == 0) {
				ans += "0";
			}
			else if (count == 1) {
				ans += "1";
				count = 0;
			}
			else if (count == 2) {
				ans += "0";
				count = 1;
			}
			else if (count == 3) {
				ans += "1";
				count = 1;
			}
		}

		// 81자리 가능성!
		if (count == 1)
			ans += "1";

		// 다시 뒤집어서 앞에 0제외하고 출력
		reverse(ans.begin(), ans.end());
		int i = 0;
		for (; i < ans.size(); ++i) {
			if (ans[i] == '1')
				break;
			if (i == ans.size() - 1)
				cout << 0;
		}
		for (; i < ans.size(); ++i) {
			cout << ans[i];
		}
		cout << "\n";
		
	}

	return 0;
}