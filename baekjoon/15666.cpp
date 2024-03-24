#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int input[9];
int output[9];

void solve(int d, int s) {
	if (d == M) {
		for (int i = 0; i < M; ++i) {
			cout << output[i] << " ";
		}
		cout << "\n";
		return;
	}

	int pre = -1;
	for (int i = s; i < N; ++i) {
		if (pre == input[i]) continue;
		output[d] = input[i];
		solve(d + 1, i);
		pre = input[i];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		cin >> input[i];
	}

	sort(input, input + N);

	solve(0, 0);

	return 0;
}