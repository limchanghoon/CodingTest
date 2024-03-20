#include <iostream>
#include <queue>

using namespace std;

const int dr[8] = { -1,-1,+0,+1,+1,+1,+0,-1 };
const int dc[8] = { +0,+1,+1,+1,+0,-1,-1,-1 };

int M, N;
int table[250][250];
bool visited[250][250];

bool isValid(int r, int c) {
	if (r < 0 || r >= M || c < 0 || c >= N) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int ans = 0;
	cin >> M >> N;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> table[i][j];
		}
	}

	queue<pair<int, int>> q;
	for (int i = 0; i < M; ++i) {
		for (int j = 0; j < N; ++j) {
			if (visited[i][j] || table[i][j] == 0) continue;
			q.push({ i,j });
			visited[i][j] = true;
			while (!q.empty()) {
				int r = q.front().first;
				int c = q.front().second;
				q.pop();

				for (int i = 0; i < 8; ++i) {
					int nextR = r + dr[i], nextC = c + dc[i];
					if (!isValid(nextR, nextC) || visited[nextR][nextC] || table[nextR][nextC] == 0) continue;
					q.push({ nextR, nextC });
					visited[nextR][nextC] = true;
				}
			}
			++ans;
		}
	}

	cout << ans;

	return 0;
}