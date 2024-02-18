#include <iostream>
#include <queue>

using namespace std;

int N;

const int dr[4] = { +1,-1,+0,+0 };
const int dc[4] = { +0,+0,+1,-1 };

string table[25];
bool visited[25][25];

bool checkValid(int r, int c) {
	if (r < 0 || r >= N || c < 0 || c >= N)
		return false;
	return true;
}

int dfs(int r, int c) {
	if (table[r][c] == '0' || visited[r][c])
		return 0;
	visited[r][c] = true;

	int cnt = 1;
	for (int i = 0; i < 4; ++i) {
		int nextR = r + dr[i];
		int nextC = c + dc[i];
		if (checkValid(nextR, nextC))
			cnt += dfs(nextR, nextC);
	}
	return cnt;
}

int main() {
	cin >> N;

	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 0; i < N; ++i) {
		cin >> table[i];
	}

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int cnt = dfs(i, j);
			if (cnt != 0)
				pq.push(cnt);
		}
	}

	cout << pq.size() << endl;
	while (!pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}

	return 0;
}

/*
* 이전 풀이
* 
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


*/