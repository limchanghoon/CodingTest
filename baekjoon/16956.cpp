#include <iostream>
#include <string>

using namespace std;

int R, C;

string table[500];

const int dr[4] = { +1,-1,+0,+0 };
const int dc[4] = { +0,+0,+1,-1 };

bool checkSafe(int r, int c) {
	// 범위 밖(늑대 없음)
	if (r < 0 || r >= R || c < 0 || c >= C)
		return true;

	if (table[r][c] == 'W')
		return false;
	return true;
}

bool solve() {
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (table[i][j] == 'S') {
				for (int k = 0; k < 4; ++k) {
					if (!checkSafe(i + dr[k], j + dc[k])) {
						return false;
					}
				}
			}
		}
	}

	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; ++i) {
		cin >> table[i];
		for (int j = 0; j < C; ++j) {
			if (table[i][j] == '.') {
				table[i][j] = 'D';
			}
		}
	}

	if (!solve()) {
		cout << 0;
		return 0;
	}

	cout << 1 << "\n";
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			cout << table[i][j];
		}
		cout << "\n";
	}

	return 0;
}