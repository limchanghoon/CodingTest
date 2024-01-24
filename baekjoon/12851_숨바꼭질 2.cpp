#include <iostream>
#include <queue>
#include <tuple>
#include <limits>

using namespace std;

#define MAXPOS 100000

bool isValid(int pos) {
	if (pos < 0 || pos > MAXPOS)
		return false;
	return true;
}

void setNext(vector<vector<int>>& counts, queue<int>& q, int next, int pre, int time) {
	if (isValid(next)) {
		if (counts[next][0] > time) {
			counts[next][0] = time;
			q.push(next);
		}
		if (counts[next][0] == time)
			counts[next][1] += counts[pre][1];
	}
}

pair<int, int> BFS(int N, int K) {
	int ansTime = numeric_limits<int>::max();
	vector<vector<int>> counts(MAXPOS + 1, vector<int>({ numeric_limits<int>::max() ,0})); // 최소 시간,경우의 수
	queue<int> q;
	q.push(N);
	counts[N][0] = 0;
	counts[N][1] = 1;
	while (!q.empty()) {
		int pos = q.front(), time = counts[pos][0];
		q.pop();

		if (pos == K && ansTime == numeric_limits<int>::max())
			ansTime = time;
		if (ansTime < time)
			break;
		++time;
		setNext(counts, q, pos - 1, pos, time);
		setNext(counts, q, pos + 1, pos, time);
		setNext(counts, q, pos * 2, pos, time);
	}
	return { counts[K][0], counts[K][1] };
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, K;
	cin >> N >> K;

	int ansTime, ansCount;
	tie(ansTime, ansCount)=BFS(N, K);
	cout << ansTime << "\n" << ansCount;
	return 0;
}