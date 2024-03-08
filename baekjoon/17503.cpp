#include <iostream>
#include <vector>
#include <algorithm>

#define BIGVALUE 2222222222

using namespace std;

int N, M, K;

bool CMP(pair<int,int> a, pair<int,int> b) {
	return a.first > b.first;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;

	long long answer = BIGVALUE;
	vector<pair<int, int>> vec;

	for (int i = 0; i < K; ++i) {
		int v, c;
		cin >> v >> c;
		vec.push_back({ v,c });
	}
	sort(vec.begin(), vec.end(), CMP);

	long long left = 1, right = ((long long)1 << 31) - 1, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		int sum = 0, count = 0;
		for (int i = 0; i < K; ++i) {
			if (vec[i].second <= mid) {
				sum += vec[i].first;
				++count;
			}
			if (count == N)
				break;
		}
		if (count == N && sum >= M) {
			answer = min(answer, mid);
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	if (answer == BIGVALUE)	cout << -1;
	else cout << answer;

	return 0;
}