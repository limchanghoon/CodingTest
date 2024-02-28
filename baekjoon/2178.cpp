#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct POS {
	int r, c, cost;
};

const int dr[4] = { +1,-1,+0,+0 };
const int dc[4] = { +0,+0,+1,-1 };

int N, M;
string table[100];
bool visited[100][100];

bool isValid(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= M)
		return false;
	return true;
}

int bfs() {
	queue<POS> q;
	q.push({ 0,0,1 });
	visited[0][0] = true;
	while (!q.empty()) {
		POS cur = q.front();
		q.pop();

		if (cur.r == N - 1 && cur.c == M - 1)
			return cur.cost;

		for (int i = 0; i < 4; ++i) {
			POS next = { cur.r + dr[i], cur.c + dc[i],cur.cost + 1 };
			if (!isValid(next.r, next.c) || visited[next.r][next.c] || table[next.r][next.c] == '0')	continue;
			q.push(next);
			visited[next.r][next.c] = true;
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		string str;
		cin >> table[i];
	}

	cout << bfs();

	return 0;
}