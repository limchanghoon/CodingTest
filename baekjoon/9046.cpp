#include <iostream>
#include <string>

using namespace std;

const int ALPSIZE = 26;

int alp[ALPSIZE];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	cin.ignore();
	while (T--) {
		string str;
		int maxCount = 0;
		char maxAlp = 0;
		bool isSame = false;
		getline(cin, str);

		for (int i = 0; i < ALPSIZE; ++i) {
			alp[i] = 0;
		}

		for (int i = 0; i < str.size(); ++i) {
			if (str[i] == ' ')
				continue;
			int index = str[i] - 'a';
			++alp[index];
		}

		for (int i = 0; i < ALPSIZE; ++i) {
			if (alp[i] > maxCount) {
				maxCount = alp[i];
				maxAlp = i;
				isSame = false;
			}
			else if (alp[i] == maxCount) {
				isSame = true;
			}
		}
		if (isSame)
			cout << "?\n";
		else
			cout << (char)(maxAlp + 'a') << "\n";
	}

	return 0;
}