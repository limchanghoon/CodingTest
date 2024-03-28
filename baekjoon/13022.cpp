#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string str;
	cin >> str;

	for (int i = 0; i < str.length();) {
		// w찾기
		int cnt = 0;
		while (i < str.length() && str[i] == 'w') {
			cnt++;
			i++;
		}
		if (cnt == 0 || i >= str.length()) {
			cout << 0;
			return 0;
		}
		// o,l,f 찾기
		for (char c : {'o', 'l', 'f'}) {
			for (int j = 0; j < cnt; ++j, ++i) {
				if (i >= str.length() || str[i] != c) {
					cout << 0;
					return 0;
				}
			}
		}
	}
	
	cout << 1;
	return 0;
}