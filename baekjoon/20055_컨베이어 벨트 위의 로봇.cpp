#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N, K;
int up = 0, down = N - 1;
vector<int> hp;
deque<bool> robot;

int goBelt(int cur) {
	return cur - 1 >= 0 ? cur - 1 : 2 * N - 1;
}

int backBelt(int cur) {
	return cur + 1 <= 2 * N - 1 ? cur + 1 : 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	hp.resize(2 * N);
	robot.resize(2 * N);
	up = 0, down = N - 1;
	for (int i = 0; i < 2 * N; ++i)
		cin >> hp[i];

	int ans = 0;
	for (; K > 0; ++ans) {
		// 벨트 돌리기
		up = goBelt(up);
		down = goBelt(down);

		// 내리기
		if (robot[down])
			robot[down] = false;

		// 로봇 이동(내리는 칸에 도착하면 내리기)
		for (int i = down; i != up; i = goBelt(i)) {
			int nextPos = backBelt(i);
			if (robot[i] && hp[nextPos] > 0 && !robot[nextPos]) {
				robot[i] = false;
				robot[nextPos] = true;
				if (--hp[nextPos] == 0)
					--K;
				if (nextPos == down)
					robot[down] = false;
			}
		}

		// 올리기
		if (hp[up] > 0) {
			robot[up] = true;
			if (--hp[up] == 0)
				--K;
		}
	}

	cout << ans;
	return 0;
}