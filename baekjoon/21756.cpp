#include <iostream>

using namespace std;

int N;
int table[101];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; ++i) {
		table[i] = i;
	}

	int count = 0;
	while (N - count != 1) {
		// 홀수번 제거
		for (int i = 1; table[i] != 0; i += 2) {
			table[i] = 0;
			++count;
		}

		// 모으기
		int temp = 0;
		for (int i = 2; temp < N - count; i += 2) {
			table[++temp] = table[i];
			table[i] = 0;
		}
	}
	cout << table[1];

	return 0;
}