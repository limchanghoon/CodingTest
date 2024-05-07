#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;
	vector<vector<int>> table(N + 1);
	vector<int> lamps(M + 1);
	for (int i = 1; i <= N; ++i) {
		int K;
		cin >> K;
		for (int j = 0; j < K; ++j) {
			int temp;
			cin >> temp;
			table[i].push_back(temp);
			lamps[temp]++;
		}
	}

	// �ϳ��� ������
	for (int i = 1; i <= N; ++i) {
		bool can = true;
		for (int j = 0; j < table[i].size(); ++j) {
			int cur = table[i][j];
			lamps[cur]--;
			if (lamps[cur] <= 0) {
				can = false;
			}
		}
		if (can) {
			cout << "1";
			return 0;
		}
		for (int j = 0; j < table[i].size(); ++j) {
			int cur = table[i][j];
			lamps[cur]++;
		}
	}
	cout << "0";
	return 0;
}