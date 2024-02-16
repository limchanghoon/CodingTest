#include <iostream>
#include <algorithm>

using namespace std;

int table[10001];
int counts[40001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	long long answer = 0;

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> table[i];
		counts[table[i] + 20000]++;
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i == j)
				continue;
			int sum = (-1) * (table[i] + table[j]);
			answer += counts[20000 + sum];
			if (sum == table[i]) answer--;
			if (sum == table[j]) answer--;
		}
	}
	cout << answer/6;
	return 0;
}

/*
* 처음 풀이
#include <iostream>
#include <algorithm>

using namespace std;

int table[10001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	long long answer = 0;

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) {
		cin >> table[i];
	}

	sort(table, table + N);

	for (int i = 0; i < N - 2; ++i) {
		for (int j = i + 1; j < N - 1; ++j) {
			int sum = -1 * (table[i] + table[j]);
			int lb = lower_bound(table + j + 1, table + N, sum) - table;
			int ub = upper_bound(table + j + 1, table + N, sum) - table;
			answer += ub - lb;
		}
	}
	cout << answer;
	return 0;
}



*/