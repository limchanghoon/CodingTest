#include <iostream>

using namespace std;

const int arr[4] = { 1,5,10,50 };
bool table[1001];
int N;


void dfs(int depth, int idx, int num) {

	if (depth == N) {
		table[num] = true;
		return;
	}

	for (int i = idx; i < 4; ++i) {
		dfs(depth + 1, i, num + arr[i]);
	}
}

int solve() {
	dfs(0, 0, 0);
	int answer = 0;
	for (int i = 1; i <= 1001; ++i) {
		if (table[i])
			answer++;
	}
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	cout << solve();

	return 0;
}

/*
* 첫번째 풀이 직관적이지 않음
* 
#include <iostream>

using namespace std;

int N;

bool table[2][1001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	table[0][1] = true;
	table[0][5] = true;
	table[0][10] = true;
	table[0][50] = true;
	for (int i = 2; i <= N; ++i) {
		for (int j = 1; j <= 950; ++j) {
			if (table[i%2][j]) {
				table[(i + 1) % 2][j + 1] = true;
				table[(i + 1) % 2][j + 5] = true;
				table[(i + 1) % 2][j + 10] = true;
				table[(i + 1) % 2][j + 50] = true;
			}
			table[i % 2][j] = false;
		}
	}

	int cnt = 0;
	for (int i = 1; i <= 1000; ++i) {
		if (table[(N + 1) % 2][i])
			cnt++;
	}
	cout << cnt;

	return 0;
}
*/