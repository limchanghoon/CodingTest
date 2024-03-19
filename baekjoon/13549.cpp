#include <iostream>
#include <queue>

using namespace std;

int N, K;
bool visited[100001];

bool isOK(int next) {
	if (next < 0 || next > 100000 || visited[next])
		return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	queue<pair<int, int>> q;
	q.push({ N, 0 });
	visited[N] = true;

	while (!q.empty()) {
		int cur = q.front().first;
		int depth = q.front().second;
		q.pop();

		if (cur == K) {
			cout << depth;
			return 0;
		}

		int next = cur;
		while (isOK(next *= 2)) {
			visited[next] = true;
			q.push({ next, depth });
		}

		next = cur - 1;
		if (isOK(next)) {
			visited[next] = true;
			q.push({ next, depth + 1 });
		}

		next = cur + 1;
		if (isOK(next)) {
			visited[next] = true;
			q.push({ next, depth + 1 });
		}
	}

	return 0;
}