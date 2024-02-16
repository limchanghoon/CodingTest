#include <iostream>
#include <string>
#include <queue>

using namespace std;

int N, K;
string s;

void solve() {
	queue<int> table[10];
	for (int i = 0; i < N; ++i) {
		int cur = s[i] - '0';
		for (int i = 0; i < cur; ++i) {
			while (!table[i].empty()) {
				s[table[i].front()] = ' ';
				table[i].pop();
				if (--K == 0)
					return;
			}
		}
		table[cur].push(i);
	}

	for (int i = 0; i < 10; ++i) {
		while (!table[i].empty()) {
			s[table[i].front()] = ' ';
			table[i].pop();
			if (--K == 0)
				return;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	cin >> s;

	solve();

	for (int i = 0; i < N; ++i)
		if (s[i] != ' ')
			cout << s[i];

	return 0;
}