#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;

int table[50000];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; ++i) {
		cin >> table[i];
	}
	queue<int> q;
	int answer = 0;
	int counter = 0;
	int sum = 0;
	int temp = 0;
	for (int i = 0; i < N; ++i) {
		if (table[i] % 2 == 0) {
			temp++;
			sum++;
		}
		else {
			if (++counter >= K + 1) {
				answer = max(answer, sum);
				sum -= q.front();
				q.pop();
			}
			q.push(temp);
			temp = 0;
		}
	}
	answer = max(answer, sum);

	cout << answer;

	return 0;
}