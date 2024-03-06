#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string input;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int sz = 0;
	cin >> input;
	for (int i = 0; i < input.length(); ++i) {
		if (input[i] == 'a')
			++sz;
	}

	int b = 0;
	for (int i = 0; i < sz; ++i) {
		if (input[i] == 'b')
			b++;
	}

	int ans = b;
	for (int i = 0; i < input.length(); ++i) {
		if (input[(i + sz) % input.length()] == 'b')
			++b;
		if (input[i] == 'b')
			--b;
		ans = min(ans, b);
	}

	cout << ans;

	return 0;
}