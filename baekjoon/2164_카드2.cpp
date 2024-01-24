#include <iostream>
#include <queue>

using namespace std;

int solve(int N)
{
	queue<int> q;
	for (int i = 0; i < N; ++i)
		q.push(i + 1);
	while (q.size() > 1) {
		q.pop();
		q.push(q.front());
		q.pop();
	}
	return q.front();
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	cout << solve(N);
	return 0;
}