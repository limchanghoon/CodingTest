#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX_VALUE 10001

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, ans = 0;
	cin >> N;
	// 스택 메모리 경고로 힙사용
	vector<int> ropes(MAX_VALUE);
	for (int i = 0; i < N; ++i) {
		int temp;
		cin >> temp;
		++ropes[temp];
	}

	for (int i = 1; i < MAX_VALUE; ++i) {
		if (ropes[i] == 0)	continue;
		ans = max(ans, N * i);
		N -= ropes[i];
	}
	
	cout << ans;

	return 0;
}