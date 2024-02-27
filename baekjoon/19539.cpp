#include <iostream>

using namespace std;

int N;
int table[100000];

bool solve() {
	cin >> N;
	int sum = 0;
	for (int i = 0; i < N; ++i) {
		cin >> table[i];
		sum += table[i];
	}
	if (sum % 3 != 0)	return false;

	int sz = sum / 3;
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		cnt += table[i] / 2;
	}
	if (sz <= cnt)	
		return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	if (solve()) cout << "YES";
	else cout << "NO";

	return 0;
}