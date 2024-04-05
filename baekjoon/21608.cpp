#include <iostream>
#include <vector>

using namespace std;

const int dr[4] = { +1,-1,+0,+0 };
const int dc[4] = { +0,+0,+1,-1 };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int ans = 0;
	int N;
	cin >> N;
	vector<vector<int>> likes(N * N + 2, vector<int>(4));
	vector<vector<int>> table(N * N + 2, vector<int>(N * N + 2));
	vector<vector<int>> counts(N * N + 2, vector<int>(N * N + 2));

	// 빈칸 갯수 초기화
	counts[1][1] = 2;
	counts[1][N] = 2;
	counts[N][1] = 2;
	counts[N][N] = 2;
	for (int i = 2; i < N; ++i) {
		counts[i][1] = 3;
		counts[i][N] = 3;

		counts[1][i] = 3;
		counts[N][i] = 3;
	}
	for (int i = 2; i < N; ++i) {
		for (int j = 2; j < N; ++j) {
			counts[i][j] = 4;
		}
	}

	for (int i = 0; i < N * N; ++i) {

		int num, A, B, C, D;
		cin >> num >> A >> B >> C >> D;
		likes[num][0] = A;
		likes[num][1] = B;
		likes[num][2] = C;
		likes[num][3] = D;

		// 조건 1
		bool isOne = false;
		int maxCount = -1;
		int RR = N;
		int CC = N;
		for (int r = N; r >= 1; --r) {
			for (int c = N; c >= 1; --c) {
				if (table[r][c] != 0) continue;
				int count = 0;
				for (int k = 0; k < 4; ++k) {
					int next = table[r + dr[k]][c + dc[k]];
					if (next == A || next == B || next == C || next == D) count++;
				}
				if (count >= maxCount) {
					isOne = count > maxCount;
					maxCount = count;
					RR = r;
					CC = c;
				}
			}
		}


		if (isOne) {
			table[RR][CC] = num;
			for (int k = 0; k < 4; ++k) {
				counts[RR + dr[k]][CC + dc[k]]--;
			}
			continue;
		}

		// 조건 2
		int maxBlankCount = -1;
		RR = N;
		CC = N;
		for (int r = N; r >= 1; --r) {
			for (int c = N; c >= 1; --c) {
				if (table[r][c] != 0) continue;
				int count = 0;
				for (int k = 0; k < 4; ++k) {
					int next = table[r + dr[k]][c + dc[k]];
					if (next == A || next == B || next == C || next == D) count++;
				}
				if (count != maxCount) continue;


				int blankCount = counts[r][c];
				if (blankCount >= maxBlankCount) {
					maxBlankCount = blankCount;
					RR = r;
					CC = c;
				}
			}
		}
		table[RR][CC] = num;
		for (int k = 0; k < 4; ++k) {
			counts[RR + dr[k]][CC + dc[k]]--;
		}
	}


	// 만족도 구하기
	for (int r = N; r >= 1; --r) {
		for (int c = N; c >= 1; --c) {
			int count = 0;
			int num = table[r][c];
			for (int k = 0; k < 4; ++k) {
				int next = table[r + dr[k]][c + dc[k]];
				if (next == likes[num][0] || next == likes[num][1] || next == likes[num][2] || next == likes[num][3]) count++;
			}
			if (count == 1) ans += 1;
			else if (count == 2) ans += 10;
			else if (count == 3) ans += 100;
			else if (count == 4) ans += 1000;
		}
	}

	cout << ans;

	return 0;
}