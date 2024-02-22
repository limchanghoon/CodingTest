#include <iostream>
#include <algorithm>

using namespace std;

int N, answer = -99999999;

int table[301][301];
int recSum[301][301];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			cin >> table[i][j];
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			recSum[i][j] = recSum[i - 1][j] + recSum[i][j - 1] - recSum[i - 1][j - 1] + table[i][j];
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			for (int k = 0; k + i <= N && k + j <= N; ++k) {
				int sum = recSum[i + k][j + k] - recSum[i - 1][j + k] - recSum[i + k][j - 1] + recSum[i - 1][j - 1];
				answer = max(answer, sum);
			}
		}
	}

	cout << answer;

	return 0;
}

/*
* 첫 풀이(느림)
* 
#include <iostream>
#include <algorithm>

using namespace std;

int N, answer;

int table[300][300];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> table[i][j];
		}
	}
	answer = table[0][0];

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int sum = 0;
			for (int r = 0; i + r < N && j + r < N; ++r) {
				for (int c = 0; c <= r; ++c) {
					sum += table[i + r][j + c];
					sum += table[i + c][j + r];
				}
				sum -= table[i + r][j + r];
				answer = max(answer, sum);
			}
		}
	}
	cout << answer;
	return 0;
*/