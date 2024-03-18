#include <iostream>

using namespace std;

int N, M;
int table[4001];

void solve(int a, int b, int c) {
	if (a == 1) {
		table[b] = c;
	}
	else if (a == 2) {
		for (int i = b; i <= c; ++i) {
			table[i] = table[i] == 1 ? 0 : 1;
		}
	}
	else if (a == 3) {
		for (int i = b; i <= c; ++i) {
			table[i] = 0;
		}
	}
	else if (a == 4) {
		for (int i = b; i <= c; ++i) {
			table[i] = 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		cin >> table[i];
	}
	for (int i = 0; i < M; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		solve(a, b, c);
	}

	for (int i = 1; i <= N; ++i) {
		cout << table[i] << " ";
	}

	return 0;
}