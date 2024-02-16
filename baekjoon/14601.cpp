#include <iostream>
#include <algorithm>


using namespace std;

int K, x, y;
int table[129][129];
int num = 0;

bool checkBlank(int sz, int curX, int curY) {
	for (int i = curX; i < curX + sz; ++i) {
		for (int j = curY; j < curY + sz; ++j) {
			if (table[i][j] != 0)
				return true;
		}
	}
	return false;
}

void solve(int sz, int curX, int curY) {
	int halfSz = sz / 2;

	++num;

	if (!checkBlank(halfSz, curX + halfSz, curY + halfSz))	// 1사분면
		table[curX + halfSz][curY + halfSz] = num;
	if (!checkBlank(halfSz, curX, curY + halfSz))	// 2사분면
		table[curX + halfSz - 1][curY + halfSz] = num;
	if (!checkBlank(halfSz, curX, curY))	// 3사분면
		table[curX + halfSz - 1][curY + halfSz - 1] = num;
	if (!checkBlank(halfSz, curX + halfSz, curY))	// 4사분면
		table[curX + halfSz][curY + halfSz - 1] = num;

	if (sz == 2)
		return;

	solve(halfSz, curX + halfSz, curY + halfSz);			// 1사분면
	solve(halfSz, curX, curY + halfSz);						// 2사분면
	solve(halfSz, curX, curY);								// 3사분면
	solve(halfSz, curX + halfSz, curY);						// 4사분면
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> K >> x >> y;
	table[x][y] = -1;
	int sz = (1 << K);
	solve(sz, 1, 1);
	
	for (int i = sz; i > 0; --i) {
		for (int j = 1; j <= sz; ++j) {
			cout << table[j][i] << " ";
		}
		cout << "\n";
	}

	return 0;
}