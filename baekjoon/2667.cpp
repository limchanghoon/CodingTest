#include <iostream>
#include <vector>
#include <deque>
#include <queue>

using namespace std;

int main()
{
	int N;
	cin >> N;


	queue<pair<int, int>> q;
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<string> table;
	deque<deque<bool>> visited(N,deque<bool>(N));


	for (int i = 0; i < N; ++i)
	{
		string s;
		cin >> s;
		table.push_back(s);
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int cnt = 0;
			q.push(make_pair(i, j));
			while (!q.empty())
			{
				int r = q.front().first;
				int c = q.front().second;
				q.pop();

				if (table[r][c] == '0' || visited[r][c])	continue;

				visited[r][c] = true;
				++cnt;

				if (r + 1 < N)
					q.push(make_pair(r + 1, c));
				if (r - 1 >= 0)
					q.push(make_pair(r - 1, c));
				if (c + 1 < N)
					q.push(make_pair(r, c + 1));
				if (c - 1 >= 0)
					q.push(make_pair(r, c - 1));
			}
			if(cnt != 0)
				pq.push(cnt);
		}
	}


	cout << pq.size() << endl;
	while (!pq.empty())
	{
		cout << pq.top() << endl;
		pq.pop();
	}

	return 0;
}