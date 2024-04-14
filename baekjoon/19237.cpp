#include <iostream>
#include <vector>

using namespace std;

struct Shark {
	int r, c, dir;
	bool isOut;
};

struct Smell {
	int num, life;
};

const int dr[5] = { +0,-1,+1,+0,+0 };
const int dc[5] = { +0,+0,+0,-1,+1 };

int N, M, K;
vector<vector<Smell>> smells;
//빈칸,위,아래,왼,오른
vector<vector<vector<int>>> prioirty;
vector<Shark> sharks;

void input() {
	cin >> N >> M >> K;
	smells.resize(N, vector<Smell>(N));
	prioirty.resize(M + 1, vector<vector<int>>(5, vector<int>(4)));
	sharks.resize(M + 1);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int temp;
			cin >> temp;
			if (temp == 0) continue;
			sharks[temp].r = i;
			sharks[temp].c = j;
			smells[i][j].life = K;
			smells[i][j].num = temp;
		}
	}
	for (int i = 1; i <= M; ++i) {
		cin >> sharks[i].dir;
	}

	for (int i = 1; i <= M; ++i) {
		for (int j = 1; j <= 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				cin >> prioirty[i][j][k];
			}
		}
	}
}

bool check(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= N) return false;
	return true;
}

void solve() {
	for (int timer = 1; timer <= 1000; ++timer) {
		
		for (int i = 1; i <= M; ++i) {
			// 1. 냄새가 없는 곳으로 이동
			if (sharks[i].isOut) continue;
			bool isMoved = false;
			int r = sharks[i].r;
			int c = sharks[i].c;
			int dir = sharks[i].dir;
			for (int j = 0; j < 4; ++j) {
				int nextR = r + dr[prioirty[i][dir][j]];
				int nextC = c + dc[prioirty[i][dir][j]];
				if (!check(nextR, nextC) || smells[nextR][nextC].life > 0) continue;
				sharks[i].r = nextR;
				sharks[i].c = nextC;
				sharks[i].dir = prioirty[i][dir][j];
				isMoved = true;
				break;
			}

			// 2. 이동 못한 상어만 자기 냄새로 이동
			if (isMoved) continue;
			for (int j = 0; j < 4; ++j) {
				int nextR = r + dr[prioirty[i][dir][j]];
				int nextC = c + dc[prioirty[i][dir][j]];
				if (!check(nextR, nextC) || smells[nextR][nextC].num != i) continue;
				sharks[i].r = nextR;
				sharks[i].c = nextC;
				sharks[i].dir = prioirty[i][dir][j];
				break;
			}
		}

		int cnt = 0;
		// 3. 이동한 장소에 냄새 저장(K+1)
		for (int i = 1; i <= M; ++i) {
			if (sharks[i].isOut) continue;
			int r = sharks[i].r;
			int c = sharks[i].c;
			if (smells[r][c].num == 0 || smells[r][c].num == i) {
				smells[r][c].life = K+1;
				smells[r][c].num = i;
				cnt++;
			}
			else {
				sharks[i].isOut = true;
			}
		}

		// 4. 냄새 -1
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (--smells[i][j].life <= 0)
					smells[i][j].num = 0;
			}
		}

		// 5. 상어 하나만 남았는지 체크
		if (cnt == 1) {
			cout << timer;
			return;
		}
	}
	cout << -1;
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	input();
	solve();
	return 0;
}