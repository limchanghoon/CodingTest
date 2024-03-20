#include <iostream>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string n;
	while (true) {
		cin >> n;
		if (n == "0") return 0;
		bool check = true;
		for (int i = 0; i < n.length() / 2; ++i) {
			if (n[i] != n[n.length() - 1 - i]) {
				check = false;
				break;
			}
		}
		if (check) cout << "yes" << "\n";
		else cout << "no" << "\n";
	}

	return 0;
}