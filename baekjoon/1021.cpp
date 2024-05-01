#include <iostream>
#include <deque>
#include <cstdlib>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M, answer = 0;
	cin >> N >> M;

	deque<int> table(N);
	for (int i = 0; i < N; ++i)
		table[i] = i + 1;

	for (int i = 0; i < M; ++i) {
		int input;
		cin >> input;

		int idx = 0;
		for (; idx < table.size(); ++idx) {
			if (table[idx] == input) break;
		}

		int goBack = abs((int)table.size() - idx);
		if (goBack < idx) {
			int last = table.size() - 1;
			while (goBack--) {
				int temp = table[last];
				table.pop_back();
				table.push_front(temp);
				answer++;
			}
		}
		else {
			while (idx--) {
				int temp = table[0];
				table.pop_front();
				table.push_back(temp);
				answer++;
			}
		}

		table.pop_front();
	}
	cout << answer;
	
	return 0;
}