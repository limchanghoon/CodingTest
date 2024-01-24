#include <iostream>
#include <queue>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

queue<int> alp[26];

void clearAlp() {
	for (int i = 0; i < 26; ++i) {
		while (!alp[i].empty()) {
			alp[i].pop();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		clearAlp();
		int ans_Min = numeric_limits<int>::max(), ans_Max = 0;
		string W;
		int K;
		cin >> W >> K;
		for (int j = 0; j < W.size(); ++j) {
			int curAlp = W[j] - 'a';
			alp[curAlp].push(j);

			if (alp[curAlp].size() == K + 1)
				alp[curAlp].pop();

			if (alp[curAlp].size() == K) {
				int temp = j - alp[curAlp].front() + 1;
				ans_Min = min(ans_Min, temp);
				ans_Max = max(ans_Max, temp);
			}
		}

		if (ans_Min == numeric_limits<int>::max())
			cout << -1 << "\n";
		else
			cout << ans_Min << " " << ans_Max << "\n";
	}

	return 0;
}