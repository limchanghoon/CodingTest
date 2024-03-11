#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, M;
int ans[10];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	while (T--) {
		cin >> M;
		cout << M / 2 + 1 << "\n";
		priority_queue<int> pq;								// 12(head)
		priority_queue<int,vector<int>,greater<int>> pq2;   //   (head)345

		int cnt = 0;
		for (int i = 1; i <= M; ++i) {
			int a;
			cin >> a;
			pq2.push(a);
			if (i % 2 == 1) {
				// pq�� ���� ��, pq2�� ū ��
				while (!pq.empty() && !pq2.empty() && pq.top() > pq2.top()) {
					pq.push(pq2.top());
					pq2.pop();
				}

				// ���� ���߱�
				while (pq.size() > pq2.size()) {
					pq2.push(pq.top());
					pq.pop();
				}

				while (pq.size() + 1 != pq2.size()) {
					pq.push(pq2.top());
					pq2.pop();
				}
				ans[cnt++] = pq2.top();
			}
			// 10���� ���� ���
			if (cnt == 10 || i == M) {
				for (int j = 0; j < cnt; ++j) {
					cout << ans[j] << " ";
				}
				cnt = 0;
				cout << "\n";
			}
		}
	}
	return 0;
}