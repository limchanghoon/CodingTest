#include <iostream>
#include <string>
#include <stack>

using namespace std;

int R, C, N;
string table[30000];
stack<pair<int, int>> points[30];

bool checkValid(int curR, int curC) {
	if (curR < 0 || curR >= R || curC < 0 || curC >= C)
		return false;
	return true;
}


void drop(int t) {
	int curR = 0;
	int curC = t - 1;
	int initC = curC;

	while (!points[initC].empty()) {
		int _r = points[initC].top().first;
		int _c = points[initC].top().second;
		points[initC].pop();
		if (table[_r][_c] == '.') {
			curR = _r;
			curC = _c;
			break;
		}
	}

	while (true) {

		points[initC].push({ curR,curC });

		// 1
		if (!checkValid(curR + 1, curC) || table[curR + 1][curC] == 'X') {
			break;
		}

		// 2
		if (checkValid(curR + 1, curC) && table[curR + 1][curC] == '.') {
			curR = curR + 1;
			continue;
		}
		
		// 3.1
		if (checkValid(curR, curC - 1) && checkValid(curR + 1, curC - 1) && table[curR][curC - 1] == '.' && table[curR + 1][curC - 1] == '.') {
			curR = curR + 1;
			curC = curC - 1;
			continue;
		}

		// 3.2
		if (checkValid(curR, curC + 1) && checkValid(curR + 1, curC + 1) && table[curR][curC + 1] == '.' && table[curR + 1][curC + 1] == '.') {
			curR = curR + 1;
			curC = curC + 1;
			continue;
		}

		break;
	}
	table[curR][curC] = 'O';
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; ++i) {
		cin >> table[i];
	}

	cin >> N;
	for (int i = 0; i < N; ++i) {
		int t;
		cin >> t;
		drop(t);
	}

	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cout << table[i][j];
		}
		cout << "\n";
	}
	return 0;
}