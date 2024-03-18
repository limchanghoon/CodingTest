#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct POS {
	int r;
	int c;
};

const int dr[4] = { +1,-1,+0,+0 };
const int dc[4] = { +0,+0,+1,-1 };

int M, N;
vector<string> table;

bool isValid(int r, int c) {
	if (r < 0 || r >= M || c < 0 || c >= N) return false;
	return true;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string ans = "NO";
	cin >> M >> N;
	table.resize(M);
	for (int i = 0; i < M; ++i) {
		cin >> table[i];
	}
	queue<POS> q;

	for (int i = 0; i < M; ++i) {
		q.push({ 0,i });
	}

	while (!q.empty()) {
		POS pos = q.front();
		q.pop();

		if (!isValid(pos.r, pos.c)) continue;
		if (table[pos.r][pos.c] != '0') continue;
		if (pos.r == M - 1) {
			ans = "YES";
			break;
		}
		table[pos.r][pos.c] = '2';

		for (int i = 0; i < 4; ++i) {
			q.push({ pos.r + dr[i],pos.c + dc[i] });
		}
	}

	cout << ans;

	return 0;
}