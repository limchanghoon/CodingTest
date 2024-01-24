#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, K;
	cin >> N >> K;
	// [��,��,��,����]
	vector<vector<int>> table(N, vector<int>(4));

	// 1. �Է� �ޱ�
	for (int i = 0; i < N; ++i) {
		cin >> table[i][3];
		cin >> table[i][0];
		cin >> table[i][1];
		cin >> table[i][2];
	}

	// 2. �����ϱ�
	sort(table.begin(), table.end(), [](vector<int>& a, vector<int>& b) {
		if (a[0] != b[0])
			return a[0] > b[0];
		else if (a[1]!=b[1])
			return a[1] > b[1];
		else
			return a[2] > b[2];
		});

	// 3. ��� ����ϱ�
	int medal[3] = { 10000000,10000000,10000000 };
	int rank = 0;
	int sameCount = 0;
	for (int i = 0; i < N; ++i) {
		if (medal[0] > table[i][0] || medal[1] > table[i][1] || medal[2] > table[i][2]) {
			rank += 1 + sameCount;
			sameCount = 0;
			for(int j =0;j<3;++j)
				medal[j] = table[i][j];
		}
		else {
			++sameCount;
		}
		if (table[i][3] == K)
			break;
	}
	cout << rank;

	return 0;
}