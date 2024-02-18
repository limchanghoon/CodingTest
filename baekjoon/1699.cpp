#include <iostream>
#include <algorithm>

using namespace std;

int N;

int table[100001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; ++i)
		table[i] = i;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j * j <= i; ++j) {
			table[i] = min(table[i], table[i - j * j] + 1);
		}
	}

	cout << table[N];
	return 0;
}