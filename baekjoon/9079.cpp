/*
* 첫 풀이, 연산이 너무 난잡함
* 
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

bool visited[513];

int flip(int d) {
	if (d == 0) return 1;
	else return 0;
}

int flipRow(int cur, int r) {
	int temp[9];
	for (int i = 0; i < 9; ++i) {
		temp[i] = cur % 2;
		cur /= 2;
	}
	temp[0 + r * 3] = flip(temp[0 + r * 3]);
	temp[1 + r * 3] = flip(temp[1 + r * 3]);
	temp[2 + r * 3] = flip(temp[2 + r * 3]);
	int result = 0;
	for (int i = 0; i < 9; ++i) {
		result += temp[i] << i;
	}
	return result;
}

int flipCol(int cur, int c) {
	int temp[9];
	for (int i = 0; i < 9; ++i) {
		temp[i] = cur % 2;
		cur /= 2;
	}
	temp[0 + c] = flip(temp[0 + c]);
	temp[3 + c] = flip(temp[3 + c]);
	temp[6 + c] = flip(temp[6 + c]);
	int result = 0;
	for (int i = 0; i < 9; ++i) {
		result += temp[i] << i;
	}
	return result;
}

int flipCross(int cur, int c) {
	int temp[9];
	for (int i = 0; i < 9; ++i) {
		temp[i] = cur % 2;
		cur /= 2;
	}
	temp[0 + c * 2] = flip(temp[0 + c * 2]);
	temp[4] = flip(temp[4]);
	temp[8 - c * 2] = flip(temp[8 - c * 2]);
	int result = 0;
	for (int i = 0; i < 9; ++i) {
		result += temp[i] << i;
	}
	return result;
}

bool isOK(int cur) {
	int temp[9];
	for (int i = 0; i < 9; ++i) {
		temp[i] = cur % 2;
		cur /= 2;
	}
	for (int i = 0; i < 8; ++i) {
		if (temp[i] != temp[i + 1])
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int first = 0;
		int ans = 99999999;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < 9; ++i) {
			char c;
			cin >> c;
			int temp = c == 'H' ? 0 : 1;

			first += temp * (1 << i);
		}

		queue<pair<int, int>> q;
		q.push({ first, 0 });
		visited[first] = true;

		while (!q.empty()) {
			int cur = q.front().first;
			int cost = q.front().second;
			q.pop();

			if (isOK(cur)) {
				ans = cost;
				break;
			}

			// 가로 뒤집기
			for (int i = 0; i < 3; ++i) {
				int next = flipRow(cur, i);
				if (!visited[next]) {
					visited[next] = true;
					q.push({ next, cost + 1 });
				}
			}

			// 세로 뒤집기
			for (int i = 0; i < 3; ++i) {
				int next = flipCol(cur, i);
				if (!visited[next]) {
					visited[next] = true;
					q.push({ next, cost + 1 });
				}
			}

			// 대각선 뒤집기
			for (int i = 0; i < 2; ++i) {
				int next = flipCross(cur, i);
				if (!visited[next]) {
					visited[next] = true;
					q.push({ next, cost + 1 });
				}
			}

		}

		if (ans == 99999999) cout << -1 << "\n";
		else cout << ans << "\n";
	}


	return 0;
}
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int rhds[8] = { 1+2+4, 8+16+32, 64+128+256, 1+8+64, 2+16+128, 4+32+256, 1+16+256, 4+16+64 };
bool visited[513];

int flip(int d) {
	if (d == 0) return 1;
	else return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int first = 0;
		int ans = 99999999;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < 9; ++i) {
			char c;
			cin >> c;
			int temp = c == 'H' ? 0 : 1;

			first += temp * (1 << i);
		}

		queue<pair<int, int>> q;
		q.push({ first, 0 });
		visited[first] = true;

		while (!q.empty()) {
			int cur = q.front().first;
			int cost = q.front().second;
			q.pop();

			if (cur == 0 || cur == (1 << 9) - 1) {
				ans = cost;
				break;
			}

			for (int i = 0; i < 8; ++i) {
				int next = cur ^ rhds[i];
				if (visited[next]) continue;
				visited[next] = true;
				q.push({ next, cost + 1 });
			}

		}

		if (ans == 99999999) cout << -1 << "\n";
		else cout << ans << "\n";
	}


	return 0;
}