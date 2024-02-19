#include <iostream>

using namespace std;

int N;
double W;
int leafCount = 0;
int table[500001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> W;

	for (int i = 0; i < N - 1; ++i) {
		int U, V;
		cin >> U >> V;
		table[U]++;
		table[V]++;
	}

	for (int i = 2; i <= N; ++i) {
		if (table[i] == 1)
			++leafCount;
	}

	cout << fixed;
	cout.precision(6);
	cout << W / leafCount << endl;

	return 0;
}
