#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string table[5];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int maxLen = 0;

	for (int i = 0; i < 5; ++i) {
		cin >> table[i];
		maxLen = max(maxLen, (int)table[i].size());
	}

	for (int i = 0; i < maxLen; ++i) {
		for (int j = 0; j < 5; ++j) {
			if (table[j].size() > i)
				cout << table[j][i];
		}
	}

	return 0;
}