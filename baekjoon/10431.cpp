#include <iostream>

using namespace std;

int P;
int table[20];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> P;
	while (P--) {
		int T;
		cin >> T;
		for (int i = 0; i < 20; ++i) {
			cin >> table[i];
		}

		int count = 0;
		for (int i = 1; i < 20; ++i) {
			for (int j = i - 1; j >= 0; --j) {
				if (table[j] > table[j + 1]) {
					int temp = table[j + 1];
					table[j + 1] = table[j];
					table[j] = temp;
					++count;
				}
				else {
					break;
				}
			}
		}
		cout << T << " " << count << "\n";
	}

	return 0;
}