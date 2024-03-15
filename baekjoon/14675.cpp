#include <iostream>
#include <vector>

using namespace std;

int N, q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	vector<int> table(N + 1);

	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b;
		++table[a];
		++table[b];
	}
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int t, k;
		cin >> t >> k;
		if (t == 1) {
			if (N == 2) cout << "no" << "\n";
			else if (table[k] > 1) cout << "yes" << "\n";
			else cout << "no" << "\n";
		}
		else {
			cout << "yes" << "\n";
		}
	}
	return 0;
}