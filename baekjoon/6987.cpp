#include <iostream>

using namespace std;

int table[6][3];
const int pattern[3][2] = { {0,2},{1,1},{2,0} };

bool dfs(int s, int s2) {
	if (s2 == 6) {
		s = s + 1;
		s2 = s + 1;
	}

	if (s == 5) {
		if (table[5][0] == 0 && table[5][1] == 0 && table[5][2] == 0) return true;
		return false;
	}


	for (int i = 0; i < 3; ++i) {
		int x = pattern[i][0];
		int y = pattern[i][1];
		if (table[s][x] > 0 && table[s2][y] > 0) {
			table[s][x]--;
			table[s2][y]--;
			if (dfs(s, s2 + 1))return true;
			table[s][x]++;
			table[s2][y]++;
		}
	}
	return false;
}

bool solve() {
	for (int i = 0; i < 6; ++i) {
		cin >> table[i][0] >> table[i][1] >> table[i][2];
	}
	for (int i = 0; i < 6; ++i) {
		if (table[i][0] + table[i][1] + table[i][2] != 5) return false;
	}
	return dfs(0, 1);
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 4; ++i) {
		if (solve()) cout << "1 ";
		else cout << "0 ";
	}

	return 0;
}