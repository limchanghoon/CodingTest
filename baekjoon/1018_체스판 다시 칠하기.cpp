#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int getCount(const char A, const char B, int r, int c, vector<string>& board) {
	int count = 0;
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if ((i + j) % 2 == 0 && board[r + i][c + j] == A)
				++count;
			else if ((i + j) % 2 == 1 && board[r + i][c + j] == B)
				++count;
		}
	}
	return count;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, M, ans = numeric_limits<int>::max();
	cin >> N >> M;
	vector<string> board(N);
	for (int i = 0; i < N; ++i)
		cin >> board[i];

	for (int i = 0; i <= N - 8; ++i)
		for (int j = 0; j <= M - 8; ++j)
			ans = min(ans, min(getCount('W', 'B', i, j, board), getCount('B', 'W', i, j, board)));
		
	cout << ans;
	return 0;
}