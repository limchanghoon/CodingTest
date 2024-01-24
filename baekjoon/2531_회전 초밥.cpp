#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int maxCount = 0;
	int count = 0;
	int N, d, k, c;
	cin >> N >> d >> k >> c;
	vector<int> chobab(N);
	vector<int> isEaten(d+1);
	for (int i = 0; i < N; ++i)
		cin >> chobab[i];

	// 쿠폰부터 먹기
	++isEaten[c];
	++count;

	// k개 먹기
	for (int i = 0; i < k; ++i)
		if (isEaten[chobab[i]]++ == 0)
			++count;
	maxCount = count;

	// i 삭제, i+k 추가
	for (int i = 0; i < N-1; ++i)
	{
		int front = chobab[i];
		int back = chobab[(i+k)%N];
		if (--isEaten[front] == 0)
			--count;

		if (isEaten[back]++ == 0)
			++count;

		maxCount = max(maxCount, count);
	}
	cout << maxCount;
	return 0;
}