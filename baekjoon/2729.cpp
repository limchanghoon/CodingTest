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
		// ������
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		// ���� ����
		int maxSize = max(a.size(), b.size());
		a.resize(maxSize, '0');
		b.resize(maxSize, '0');

		// ���ϱ� ����
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

		// 81�ڸ� ���ɼ�!
		if (count == 1)
			ans += "1";

		// �ٽ� ����� �տ� 0�����ϰ� ���
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