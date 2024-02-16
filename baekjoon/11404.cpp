#include <iostream>
#include <algorithm>

#define MAXVALUE 11111111

using namespace std;


int n,m;
int table[101][101];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	fill_n(&table[0][0], 101 * 101, MAXVALUE);
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if(c < table[a][b])
			table[a][b] = c;
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (i == j)
				continue;
			for (int k = 1; k <= n; ++k) {
				if (i == k || j == k)
					continue;
				table[j][k] = min(table[j][k], table[j][i] + table[i][k]);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (table[i][j] == MAXVALUE)
				table[i][j] = 0;
			cout << table[i][j] <<" ";
		}
		cout << "\n";
	}
	return 0;
}