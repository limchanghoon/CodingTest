#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int table[201][4] = { 0, };	// 참가 인원, 총 점수, 5등 점수, 4등 더하기 체크 변수;
		int N;
		cin >> N;
		vector<int> info(N);
		for (int j = 0; j < N; ++j) {
			int cur;
			cin >> cur;
			info[j] = cur;
			if (++table[cur][0] == 5)	// 참가 인원 저장 & 각 팀의 5등 점수 저장
				table[cur][2] = j + 1;
		}

		// 총 점수 계산
		for (int j = 0, rank = 1; j < N; ++j) {
			int cur = info[j];
			if (table[cur][0] == 6) {
				if (table[cur][3] < 4) {
					table[cur][1] += rank;
					++table[cur][3];
				}
				++rank;
			}
		}

		// 1등 계산
		int minPoint = numeric_limits<int>::max();
		int first = 1;
		for (int j = 1; j < 201; ++j) {
			if (table[j][0] == 6) {
				if (minPoint == table[j][1] && table[first][2] > table[j][2]) {
					first = j;
					minPoint = table[j][1];
				}
				else if (minPoint > table[j][1]) {
					first = j;
					minPoint = table[j][1];
				}
			}
		}
		cout << first << "\n";
	}

	return 0;
}