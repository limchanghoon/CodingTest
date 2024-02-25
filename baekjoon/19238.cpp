#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

struct Pos{
	int r, c;
};

const int dr[4] = { +1,-1,+0,+0 };
const int dc[4] = { +0,+0,+1,-1 };

int N, M, F;
int curR, curC;
int curCustomer;
int table[21][21];
bool visited[21][21];
Pos des[401];


void input() {
	cin >> N >> M >> F;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> table[i][j];
			if (table[i][j] == 1)
				table[i][j] = -1;
		}
	}
	cin >> curR >> curC;
	for (int i = 1; i <= M; ++i) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		table[a][b] = i;
		des[i] = { c, d };
	}
}

bool check(int r, int c) {
	if (r <= 0 || r > N || c <= 0 || c > N || table[r][c] == -1)
		return false;
	return true;
}

bool cmp(Pos a, Pos b) {
	if (a.r == b.r)
		return a.c < b.c;
	return a.r < b.r;
}

bool find_customer() {
	queue<pair<Pos,int>> q;
	vector<Pos> vec;
	memset(visited, false, sizeof(visited));
	q.push({ {curR, curC}, 0 });
	visited[curR][curC] = true;
	int temp = 999999999;
	while (!q.empty()) {
		Pos curPos = q.front().first;
		int cost = q.front().second;
		q.pop();
		if (temp < cost)
			break;

		// 다음 손님 후보군
		if (table[curPos.r][curPos.c] > 0) {
			temp = cost;
			vec.push_back(curPos);
			continue;
		}

		for (int i = 0; i < 4; ++i) {
			int nextR = curPos.r + dr[i];
			int nextC = curPos.c + dc[i];
			if (!check(nextR, nextC) || visited[nextR][nextC])	continue;
			visited[nextR][nextC] = true;
			q.push({{ nextR,nextC }, cost + 1});
		}
	}

	F -= temp;
	if (F < 0 || vec.size() == 0)
		return false;
	sort(vec.begin(), vec.end(), cmp);
	curR = vec[0].r;
	curC = vec[0].c;
	curCustomer = table[curR][curC];
	table[curR][curC] = 0;

	return true;
}

bool find_destination() {
	queue<pair<Pos, int>> q;
	memset(visited, false, sizeof(visited));
	q.push({ {curR, curC}, 0 });
	visited[curR][curC] = true;
	Pos curPos = { 0,0 };
	int cost = 0;
	bool isFound = false;
	while (!q.empty()) {
		curPos = q.front().first;
		cost = q.front().second;
		q.pop();

		// 목적지 도착
		if (des[curCustomer].r == curPos.r && des[curCustomer].c == curPos.c) {
			isFound = true;
			break;
		}


		for (int i = 0; i < 4; ++i) {
			int nextR = curPos.r + dr[i];
			int nextC = curPos.c + dc[i];
			if (!check(nextR, nextC) || visited[nextR][nextC])	continue;
			visited[nextR][nextC] = true;
			q.push({ { nextR,nextC }, cost + 1 });
		}
	}

	F -= cost;
	if (F < 0 || !isFound)
		return false;
	F += cost * 2;
	curR = curPos.r;
	curC = curPos.c;
	return true;
}

void solve() {
	for (int i = 0; i < M; ++i) {
		if (!find_customer()) {
			cout << -1;
			return;
		}
		if (!find_destination()) {
			cout << -1;
			return;
		}
	}
	cout << F;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	input();
	solve();
	return 0;
}